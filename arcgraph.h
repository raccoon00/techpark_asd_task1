#ifndef _H_ARCGRAPH
#define _H_ARCGRAPH

#include "igraph.h"

struct ArcGraph : public IGraph {
public:
    ArcGraph(int vertexCount);
    ArcGraph(const IGraph& other);
    ~ArcGraph() override {}

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    int vertexCount;
    std::vector<std::pair<int, int>> edges;
};

#endif // _H_ARCGRAPH
