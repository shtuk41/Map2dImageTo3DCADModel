#include "stdafx.h"
#include "ModelView.h"


ModelView::ModelView()
{
	mappingNet = new MappingNet();
}

ModelView::~ModelView()
{
	if (mappingNet)
	{
		delete mappingNet;
		mappingNet = 0;
	}
}

void ModelView::CreateNet(int rows, int columns)
{
	if (mappingNet)
	{
		mappingNet->SetDimentions(columns, rows);
		mappingNet->Create();
	}
}

int ModelView::GetNetElementX(unsigned int element)
{
	if (mappingNet)
	{
		return mappingNet->GetElementX(element);
	}

	return -1;
}

int ModelView::GetNetElementY(unsigned int element)
{
	if (mappingNet)
	{
		return mappingNet->GetElementY(element);
	}

	return -1;
}

bool ModelView::NetElementHasRightNode(unsigned int element)
{
	return mappingNet->ElementHasNodeRight(element);
}

bool ModelView::NetElementHasBelowNode(unsigned int element)
{
	return mappingNet->ElementHasNodeBelow(element);
}

int ModelView::GetNetElementRightEdgeX(unsigned int element)
{
	if (NetElementHasRightNode(element))
	{
		return mappingNet->GetElementNodeRightX(element);
	}

	return -1;
}

int ModelView::GetNetElementRightEdgeY(unsigned int element)
{
	if (NetElementHasRightNode(element))
	{
		return mappingNet->GetElementNodeRightY(element);
	}

	return -1;
}

int ModelView::GetNetElementBelowEdgeX(unsigned int element)
{
	if (NetElementHasBelowNode(element))
	{
		return mappingNet->GetElementNodeBelowX(element);
	}

	return -1;
}

int ModelView::GetNetElementBelowEdgeY(unsigned int element)
{
	if (NetElementHasBelowNode(element))
	{
		return mappingNet->GetElementNodeBelowY(element);
	}

	return -1;
}

void ModelView::MoveNetByDelta(int x, int y)
{
	if (mappingNet)
	{
		if (mappingNet->IsNodeSelected())
		{
			mappingNet->MoveSelectedNodeDelta(x,y);
		}
		else
		{
			mappingNet->MoveAllNodesDelta(x,y);
		}
	}
}

bool ModelView::NetTrySelectNode(int x, int y, int radius)
{
	if (mappingNet)
	{
		return mappingNet->TrySelectNode(x,y, radius);
	}

	return false;
}

void ModelView::NetTryReleaseNode()
{
	if (mappingNet)
	{
		mappingNet->TryReleaseNode();
	}
}

bool ModelView::IsNetElementSelected(unsigned int element)
{
	if (mappingNet)
	{
		return mappingNet->IsElementSelected(element);
	}

	return false;
}

void ModelView::Save(char *filename, double widthMultiplier, double heightMultiplier)
{
	if (mappingNet)
	{
		mappingNet->Save(filename, widthMultiplier, heightMultiplier);
	}
}

void ModelView::Restore(char *filename, double widthMultiplier, double heightMultiplier, int &rows, int&columns)
{
	if (mappingNet)
	{
		mappingNet->Restore(filename, widthMultiplier, heightMultiplier, rows, columns);
	}
}
