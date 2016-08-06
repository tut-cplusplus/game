#include <vector>

template <typename T>
class Graph {
private:
	class NodeNotFoundException{};

private:
	std::vector<T> nodes;
	std::vector<std::vector<unsigned char>> adjacencyMatrix;

private:
	unsigned searchNode(const T& node) const;

public:
	Graph();

	void addNode(const T& node);
	void addEdge(unsigned idx1, unsigned idx2);
	void addEdge(const T& v1, const T& v2);
	void removeNode(unsigned idx);
	void removeNode(const T& node);
	void removeEdge(unsigned idx1, unsigned idx2);
	void removeEdge(const T& v1, const T& v2);

	unsigned getNodeNum(void) const;
};

template <typename T>
unsigned Graph<T>::searchNode(const T& node) const
{
	for (unsigned i = 0; i < nodes.size(); i++) {
		const T& n = nodes[i];
		if (n == node)
			return i;
	}
	throw NodeNotFoundException();
}

template <typename T>
Graph<T>::Graph()
{
}

template <typename T>
inline void Graph<T>::addNode(const T& node)
{
	nodes.push_back(node);
	auto size = adjacencyMatrix.size();
	size++;
	adjacencyMatrix.resize(size);
	for (auto itr = adjacencyMatrix.begin(); itr != adjacencyMatrix.end(); ++itr)
		itr->resize(size);
}

template <typename T>
inline void Graph<T>::addEdge(unsigned idx1, unsigned idx2)
{
	adjacencyMatrix[idx1][idx2]++;
	adjacencyMatrix[idx2][idx1]++;
}

template <typename T>
inline void Graph<T>::addEdge(const T& v1, const T& v2)
{
	try {
		unsigned idx1 = searchNode(v1);
		unsigned idx2 = searchNode(v2);
		addEdge(idx1, idx2);
	}
	catch (const NodeNotFoundException& e) {
	}
}

template <typename T>
inline void Graph<T>::removeNode(unsigned idx)
{
	nodes.erase(nodes.begin() + idx);
	adjacencyMatrix.erase(adjacencyMatrix.begin() + idx);
	for (auto itr = adjacencyMatrix.begin(); itr != adjacencyMatrix.end(); ++itr) {
		std::vector<unsigned char>& row = *itr;
		row.erase(row.begin() + idx);
	}
}

template <typename T>
inline void Graph<T>::removeNode(const T& node)
{
	try {
		unsigned idx = searchNode(node);
		removeNode(idx);
	}
	catch (const NodeNotFoundException& e) {
	}
}

template <typename T>
inline void Graph<T>::removeEdge(unsigned idx1, unsigned idx2)
{
	adjacencyMatrix[idx1][idx2]--;
	adjacencyMatrix[idx2][idx1]--;
}

template <typename T>
inline void Graph<T>::removeEdge(const T& v1, const T& v2)
{
	try {
		unsigned idx1 = searchNode(v1);
		unsigned idx2 = searchNode(v2);
		removeEdge(idx1, idx2);
	}
	catch (const NodeNotFoundException& e) {
	}
}

template <typename T>
inline unsigned Graph<T>::getNodeNum(void) const
{
	return nodes.size();
}

