#include "setgraph.h"
#include <assert.h>


using namespace std;

SetGraph::SetGraph(int vertexCount) {
    assert(vertexCount > 0);
    neighbors.resize(vertexCount);
}

SetGraph::SetGraph(const IGraph& other) {
    int vertexCount = other.VerticesCount();

    for (int v = 0; v < vertexCount; v++) {
        vector<int> neigbors = other.GetNextVertices(v);
        neighbors.push_back(unordered_set<int>(neigbors.begin(), neigbors.end()));
    }
}

void SetGraph::AddEdge(int from, int to) {
    neighbors[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return neighbors.size();
}

vector<int> SetGraph::GetNextVertices(int vertex) const {
    vector<int> nexts(neighbors[vertex].begin(), neighbors[vertex].end());
    return nexts;
}

vector<int> SetGraph::GetPrevVertices(int vertex) const {
    vector<int> prevs;
    for (int v = 0; v < this->VerticesCount(); v++) {
        if (neighbors[v].count(vertex) > 0) {
            prevs.push_back(v);
        }
    }

    return prevs;
}
