#ifndef ___Class_Tree
#define ___Class_Tree

#include <stack>

#include "Graph.hpp"

template <typename T>
class Tree : public Graph<T> {
	std::stack<int> indexes;
	Graph<T> graph;
	int iterationNumber;
public:
	Tree(int iterationNumber);

	void depthFirstSearch(const Graph<T>& graph);
	void depthFirstSearch(const Graph<T>& graph, unsigned idx);
	void depthFirstSearch(const Graph<T>& graph, const T& node);

	void update(void);
	bool isUpdated(void) const;
};

template <typename T>
Tree<T>::Tree(int iterationNumber)
	: Graph<T>(), iterationNumber(iterationNumber)
{

}

template <typename T>
void Tree<T>::depthFirstSearch(const Graph<T>& graph)
{
	if (graph.getNodeNum())
		depthFirstSearch(graph, 0);
}

template <typename T>
void Tree<T>::depthFirstSearch(const Graph<T>& graph, unsigned idx)
{
	indexes = std::stack<int>();
	Graph<T>::nodes.clear();
	Graph<T>::adjacencyMatrix.clear();
	this->graph = graph;
	Graph<T>::addNode(graph.getNodes()[idx]);
	indexes.push(idx);
}

template <typename T>
void Tree<T>::depthFirstSearch(const Graph<T>& graph, const T& node)
{
	try {
		unsigned idx = graph.searchNode(node);
		depthFirstSearch(graph, idx);
	}
	catch (...) {
	}
}

template <typename T>
void Tree<T>::update(void)
{
	for (int i = 0; i < iterationNumber; i++) {
		if (!indexes.size())
			break;
		unsigned idx = indexes.top();
		indexes.pop();
		const T& node = graph.getNodes()[idx];
		auto row = graph.getAdjacencyMatrix()[idx];
		for (unsigned i = 0; i < row.size(); i++) {
			unsigned char value = row[i];
			if (!value)
				continue;
			const T& newNode = graph.getNodes()[i];
			try {
				Graph<T>::searchNode(newNode);
			}
			catch (...) {
				Graph<T>::addNode(newNode);
				Graph<T>::addEdge(node, newNode);
				indexes.push(i);
			}
		}
	}
}

template <typename T>
inline bool Tree<T>::isUpdated(void) const
{
	return indexes.size() == 0;
}

#endif

