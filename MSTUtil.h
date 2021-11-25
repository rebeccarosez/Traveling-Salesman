#pragma once

#include <vector>

using namespace std;

struct NodeData
{
	int m_index;
	vector<NodeData> m_edges;

	NodeData() : m_index(-1) {}
	NodeData(int index) : m_index(index) {}
};

class MSTUtil
{
public:
	static void MSTInsert(NodeData *node, int fromIdx, int toIdx);
	static void MSTTraverse(NodeData* node, vector<int> *traversal);
};