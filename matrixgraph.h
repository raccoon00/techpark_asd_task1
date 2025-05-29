#ifndef _H_MATRIXGRAPH
#define _H_MATRIXGRAPH

#include "igraph.h"

struct MatrixGraph : public IGraph {
public:
    MatrixGraph(int vertexCount);
    MatrixGraph(const IGraph& other);
    ~MatrixGraph() override {}

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::vector<bool>> matrix;
};

#endif // _H_MATRIXGRAPH
