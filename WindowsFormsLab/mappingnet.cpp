#include "stdafx.h"

#include <sstream>
#include <vector>
#include <string>
#include <fstream>

#include "mappingnet.h"
#include "../rapidxml-1.13/rapidxml.hpp"
#include "../rapidxml-1.13/rapidxml_print.hpp"

using namespace rapidxml;


MappingNode::MappingNode(int positionX , int positionY)
{
	for (int ii = 0; ii < 4; ii++)
		edges[ii] = 0;

	SetX(positionX);
	SetY(positionY);
}

void MappingNet::SetDimentions(int w, int h)
{
	width = w;
	height = h;
	selectedNode = 0;
}

MappingNet::~MappingNet()
{
	ClearNet();
}

void MappingNet::ClearNet()
{
	if (net.size() > 0)
	{
		for (std::vector<MappingNode  *>::iterator it = net.begin(); it != net.end(); ++it)
		{
			delete (*it);
		}

		net.clear();
	}
}

void MappingNet::Create()
{
	ClearNet();

	for (int ii = 0; ii < height; ii++)
	{
		for (int jj = 0; jj < width; jj++)
		{
			MappingNode  *node = new MappingNode(jj * 20, ii * 20);

			int index = width * ii + jj;

			if ((index % width) > 0)
			{
				MappingNode *leftNode = net[index - 1];
				node->SetEdge(MappingNode::LEFT, leftNode);
				leftNode->SetEdge(MappingNode::RIGHT, node);
			}

			if ((index / width) > 0)
			{
				MappingNode *aboveNode = net[index - width];
				node->SetEdge(MappingNode::ABOVE, aboveNode);
				aboveNode->SetEdge(MappingNode::BELOW, node);
			}

			net.push_back(node);
		}
	}
}

int MappingNet::GetElementX(unsigned int element)
{
	if (net.size() > element)
	{
		return net[element]->GetX();
	}

	return -1;
}

int MappingNet::GetElementY(unsigned int element)
{
	if (net.size() > element)
	{
		return net[element]->GetY();
	}

	return -1;
}

bool MappingNet::ElementHasNodeRight(unsigned int element) const
{
	bool ret = false;
	
	if (net.size() > element && net[element]->GetEdge(MappingNode::RIGHT) != 0)
		ret = true;
	
	return ret;
}

bool MappingNet::ElementHasNodeBelow(unsigned int element) const
{
	bool ret = false;
	
	if (net.size() > element && net[element]->GetEdge(MappingNode::BELOW) != 0)
		ret = true;
	
	return ret;
}

int MappingNet::GetElementNodeRightX(unsigned int element) const
{
	if (ElementHasNodeRight(element))
	{
		return net[element]->GetEdge(MappingNode::RIGHT)->GetX();
	}

	return -1;
}

int MappingNet::GetElementNodeRightY(unsigned int element) const
{
	if (ElementHasNodeRight(element))
	{
		return net[element]->GetEdge(MappingNode::RIGHT)->GetY();
	}

	return -1;
}

int MappingNet::GetElementNodeBelowX(unsigned int element) const
{
	if (ElementHasNodeBelow(element))
	{
		return net[element]->GetEdge(MappingNode::BELOW)->GetX();
	}

	return -1;
}

int MappingNet::GetElementNodeBelowY(unsigned int element) const
{
	if (ElementHasNodeBelow(element))
	{
		return net[element]->GetEdge(MappingNode::BELOW)->GetY();
	}

	return -1;
}

void MappingNet::MoveAllNodesDelta(int x,int y)
{
	int realX = x;
	int realY = y;

	for (std::vector<MappingNode *>::iterator it = net.begin(); it != net.end(); ++it)
	{
		int dX = (*it)->GetX() + realX;
		if (x > 0 && dX > 450)
		{
			realX = realX - (dX - 450);
		}
		else if (x < 0 && dX < 0)
		{
			realX = realX - dX;
		}

		int dY = (*it)->GetY() + realY;

		if (y > 0 && dY > 600)
		{
			realY = realY - (dY - 600);
		}
		else if (y < 0 && dY < 0)
		{
			realY = realY - dY;
		}
	}

	for (std::vector<MappingNode *>::iterator it = net.begin(); it != net.end(); ++it)
	{
		(*it)->SetX((*it)->GetX() + realX);
		(*it)->SetY((*it)->GetY() + realY);
	}
}

bool MappingNet::TrySelectNode(int x, int y, int radius)
{
	for (std::vector<MappingNode *>::iterator it = net.begin(); it != net.end(); ++it)
	{
		if ((*it)->GetX() < x + radius && (*it)->GetX() > x - radius &&
			(*it)->GetY() < y + radius && (*it)->GetY() > y - radius)
		{
			selectedNode = *it;
			return true;
		}
	}

	return false;
}

void MappingNet::TryReleaseNode()
{
	selectedNode = 0;
}

bool MappingNet::IsNodeSelected() const 
{
	return selectedNode != 0;
}

void MappingNet::MoveSelectedNodeDelta(int x,int y)
{
	if (IsNodeSelected())
	{
		int realX = __min(__max(selectedNode->GetX() + x,0), 450);
		int realY = __min(__max(selectedNode->GetY() + y,0), 600);

		MappingNode* left = selectedNode->GetEdge(MappingNode::LEFT);
		MappingNode* right = selectedNode->GetEdge(MappingNode::RIGHT);
		MappingNode* above = selectedNode->GetEdge(MappingNode::ABOVE);
		MappingNode* below = selectedNode->GetEdge(MappingNode::BELOW);

		if (left && realX < left->GetX() + 2)
		{
			realX = left->GetX() + 2;
		}
		else if (right && realX > right->GetX() - 2)
		{
			realX = right->GetX() - 2;
		}

		if (above && realY < above->GetY() + 2)
		{
			realY = above->GetY() + 2;
		}
		else if (below && realY > below->GetY() - 2)
		{
			realY = below->GetY() - 2;
		}

		selectedNode->SetX(realX);
		selectedNode->SetY(realY);
	}
}

bool MappingNet::IsElementSelected(unsigned int element) const
{
	if (IsNodeSelected() && selectedNode == net[element])
		return true;
	else
		return false;
}

void MappingNet::Save(char *filename, double widthMultiplier, double heightMultiplier)
{
	xml_document<> doc;
	xml_node<>* decl = doc.allocate_node(node_declaration);
	decl->append_attribute(doc.allocate_attribute("version", "1.0"));
	decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
	doc.append_node(decl);
 
	xml_node<>* root = doc.allocate_node(node_element, "map");

	std::ostringstream oss;
	oss << height;
	char *rows = new char[oss.str().length() + 1];
	strncpy(rows, oss.str().c_str(),oss.str().length() + 1);
	root->append_attribute(doc.allocate_attribute("rows", rows));

	oss.str("");
	oss.clear();
	oss << width;
	char *columns = new char[oss.str().length() + 1];
	strncpy(columns, oss.str().c_str(),oss.str().length() + 1);
	root->append_attribute(doc.allocate_attribute("columns", columns));
	doc.append_node(root);

	std::vector<char *> strmempool;

	for (int hh = 0; hh < height; hh++)
	{
		xml_node<>* rownode = doc.allocate_node(node_element, "row");
		root->append_node(rownode);

		for (int ww = 0; ww < width; ww++)
		{
			int index = hh * width + ww;

			int x = (int)(widthMultiplier * net[index]->GetX());
			int y = (int)(heightMultiplier * net[index]->GetY());

			xml_node<>* node = doc.allocate_node(node_element, "node");

			oss.str("");
			oss.clear();
			oss << x;
			std::string str = oss.str();

			char *xstr = new char[str.length() + 1];
			strncpy(xstr,str.c_str(),str.length() + 1);
			strmempool.push_back(xstr);

			node->append_attribute(doc.allocate_attribute("x2d",xstr));

			oss.str("");
			oss.clear();
			oss << y;
			str = oss.str();

			char *ystr = new char[str.length() + 1];
			strncpy(ystr,str.c_str(),str.length() + 1);
			strmempool.push_back(ystr);

			node->append_attribute(doc.allocate_attribute("y2d",ystr));

			node->append_attribute(doc.allocate_attribute("x3d",""));
			node->append_attribute(doc.allocate_attribute("y3d",""));
			node->append_attribute(doc.allocate_attribute("z3d",""));
			rownode->append_node(node);

		}
	}

	// Save to file
	std::ofstream file_stored(filename);
	file_stored << doc;
	file_stored.close();
	doc.clear();

	for (std::vector<char *>::iterator it = strmempool.begin(); it != strmempool.end(); ++it)
	{
		delete *it;
	}
}

void MappingNet::Restore(char *filename, double widthMultiplier, double heightMultiplier, int &rows, int &columns)
{
	xml_document<> doc;
	xml_node<> * root_node;

	std::ifstream theFile (filename);
	std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);
	root_node = doc.first_node("map");

	char *prows = root_node->first_attribute("rows")->value();
	char *pcolumns = root_node->first_attribute("columns")->value();

	std::stringstream ss((std::string(prows)));
	ss >> rows;
	ss.str(std::string(pcolumns));
	ss.clear();
	ss >> columns;

	SetDimentions(columns, rows);
	Create();

	int counter = 0;

	for (xml_node<> *row_node = root_node->first_node("row"); row_node; row_node = row_node->next_sibling())
	{
		for (xml_node<> *node_node = row_node->first_node("node"); node_node; node_node = node_node->next_sibling())
		{
			char *px2d = node_node->first_attribute("x2d")->value();
			char *py2d = node_node->first_attribute("y2d")->value();

			int x2d, y2d;

			ss.str(std::string(px2d));
			ss.clear();
			ss >> x2d;
			ss.str(std::string(py2d));
			ss.clear();
			ss >> y2d;
				
	    	x2d = (int)((double)x2d / widthMultiplier);
			y2d = (int)((double)y2d / heightMultiplier);

			net[counter]->SetX(x2d);
			net[counter]->SetY(y2d);
			counter++;
		}
	}
}
