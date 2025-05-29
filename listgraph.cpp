#include "listgraph.h"
#include <assert.h>


using namespace std;

ListGraph::ListGraph(int vertexCount) {
    assert(vertexCount > 0);
    neighbors.resize(vertexCount);
}

ListGraph::ListGraph(const IGraph& other) {
    int vertexCount = other.VerticesCount();
    neighbors.resize(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        neighbors[v] = other.GetNextVertices(v);
    }
}

void ListGraph::AddEdge(int from, int to) {
    neighbors[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return neighbors.size();
}

vector<int> ListGraph::GetNextVertices(int vertex) const {
    return neighbors[vertex];
}

vector<int> ListGraph::GetPrevVertices(int vertex) const {
    vector<int> prevs;
    for (int v = 0; v < this->VerticesCount(); v++) {
        for (int n : neighbors[v]) {
            if (n == vertex) {
                prevs.push_back(v);
                break;
            }
        }
    }
    return prevs;
}
