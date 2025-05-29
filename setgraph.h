#ifndef _H_SETGRAPH
#define _H_SETGRAPH

#include "igraph.h"
#include <unordered_set>

struct SetGraph : public IGraph {
public:
    SetGraph(int vertexCount);
    SetGraph(const IGraph& other);
    ~SetGraph() override {}

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::unordered_set<int>> neighbors;
};

#endif // _H_SETGRAPH
