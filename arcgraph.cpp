#include "arcgraph.h"
#include <assert.h>


using namespace std;

ArcGraph::ArcGraph(int vertexCount) : vertexCount(vertexCount) {
    assert(vertexCount > 0);
}

ArcGraph::ArcGraph(const IGraph& other) {
    vertexCount = other.VerticesCount();

    for (int v = 0; v < vertexCount; v++) {
        for (int n : other.GetNextVertices(v)) {
            this->AddEdge(v, n);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    edges.push_back({from, to});
}

int ArcGraph::VerticesCount() const {
    return vertexCount;
}

vector<int> ArcGraph::GetNextVertices(int vertex) const {
    vector<int> nexts;
    for (const auto& edge : edges) {
        if (edge.first == vertex) nexts.push_back(edge.second);
    }
    return nexts;
}

vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    vector<int> prevs;
    for (const auto& edge : edges) {
        if (edge.second == vertex) prevs.push_back(edge.first);
    }
    return prevs;
}
