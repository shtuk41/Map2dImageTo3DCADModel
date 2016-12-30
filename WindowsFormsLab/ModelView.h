#pragma once

#include "MappingNet.h"

class ModelView
{
public:
	ModelView ();
	~ModelView();

	void CreateNet(int row, int columns);
	int GetNetElementX(unsigned int element);
	int GetNetElementY(unsigned int element);
	bool NetElementHasRightNode(unsigned int element);
	bool NetElementHasBelowNode(unsigned int element);
	int GetNetElementRightEdgeX(unsigned int element);
	int GetNetElementRightEdgeY(unsigned int element);
	int GetNetElementBelowEdgeX(unsigned int element);
	int GetNetElementBelowEdgeY(unsigned int element);
	void MoveNetByDelta(int x, int y);
	bool NetTrySelectNode(int x, int y, int radius);
	void NetTryReleaseNode();
	bool IsNetElementSelected(unsigned int element);
	void Save(char *filename, double widthMultiplier, double heightMultiplier);
	void Restore(char *filename, double widthMultiplier, double heightMultiplier, int&rows, int&columns);
private:
	MappingNet *mappingNet;
};