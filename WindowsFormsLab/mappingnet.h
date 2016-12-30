#pragma once

#include <vector>
#include <string>



class MappingNode
{
public:
	enum EDGES {ABOVE = 0, BELOW, LEFT, RIGHT};
	MappingNode(int positionX , int positionY);
	int GetX() const { return x; }
	int GetY() const { return y; }
	void SetX(int positionX) {x = positionX;}
	void SetY(int positionY) {y = positionY;}
	MappingNode* GetEdge(EDGES e) {return edges[e];}
	void SetEdge(EDGES e, MappingNode *node) { edges[e] = node; }

private:
	int x;
	int y;
	MappingNode *edges[4];
};


class MappingNet
{
public:
	MappingNet(int w = 2, int h = 2) : width(w), height(h)
	{
		
	}

	~MappingNet();

	void ClearNet();
	void SetDimentions(int w, int h);
	void Create();
	int GetElementX(unsigned int element);
	int GetElementY(unsigned int element);
	bool ElementHasNodeRight(unsigned int element) const;
	bool ElementHasNodeBelow(unsigned int element) const;
	int GetElementNodeRightX(unsigned int element) const;
	int GetElementNodeRightY(unsigned int element) const;
	int GetElementNodeBelowX(unsigned int element) const;
	int GetElementNodeBelowY(unsigned int element) const;
	void MoveAllNodesDelta(int x, int y);
	bool TrySelectNode(int x, int y, int radius);
	void TryReleaseNode();
	bool IsNodeSelected() const;
	void MoveSelectedNodeDelta(int x, int y);
	bool IsElementSelected(unsigned int element) const;
	void Save(char *filename, double widthMultiplier, double heightMultiplier);
	void Restore(char *filename, double widthMultiplier, double heightMultiplier, int&rows, int&columns);

private:
	int width;
	int height;

	std::vector<MappingNode *> net;
	MappingNode *selectedNode;
};

