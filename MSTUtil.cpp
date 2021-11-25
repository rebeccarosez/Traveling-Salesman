#include "MSTUtil.h"

//insert toIdx into node tree, will branch ouf from fromIdx
//assumes only one instance of fromIdx in the tree
void MSTUtil::MSTInsert(NodeData* node, int fromIdx, int toIdx)
{
	if (node->m_index == fromIdx)
	{
		node->m_edges.push_back(NodeData(toIdx));
		return;
	}
	
	for (int i = 0; i < node->m_edges.size(); i++)
	{
		NodeData *child = &node->m_edges[i];
		MSTInsert(child, fromIdx, toIdx);
	}
}

//traverse node and put node traversal into traversal vector
void MSTUtil::MSTTraverse(NodeData* node, vector<int> *traversal)
{
	traversal->push_back(node->m_index);
	for (int i = 0; i < node->m_edges.size(); i++)
	{
		NodeData child = node->m_edges[i];
		MSTTraverse(&child, traversal);
	}
}