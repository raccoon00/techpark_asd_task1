#ifndef _H_LISTGRAPH
#define _H_LISTGRAPH

#include "igraph.h"

struct ListGraph : public IGraph {
public:
    ListGraph(int vertexCount);
    ListGraph(const IGraph& other);
    ~ListGraph() override {}
    
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> neighbors;
};

#endif // _H_LISTGRAPH
