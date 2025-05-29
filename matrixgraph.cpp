#include "matrixgraph.h"
#include <assert.h>


using namespace std;

MatrixGraph::MatrixGraph(int vertexCount) {
    assert(vertexCount > 0);
    matrix.resize(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        matrix[i].resize(vertexCount, false);
    }
}

MatrixGraph::MatrixGraph(const IGraph& other) {
    int vertexCount = other.VerticesCount();

    matrix.resize(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        matrix[i].resize(vertexCount, false);
    }

    for (int v = 0; v < vertexCount; v++) {
        for (int n : other.GetNextVertices(v)) {
            this->AddEdge(v, n);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    matrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    vector<int> nexts;
    for (int n = 0; n < this->VerticesCount(); n++) {
        if (matrix[vertex][n]) {
            nexts.push_back(n);
        }
    }

    return nexts;
}

vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    vector<int> prevs;
    for (int n = 0; n < this->VerticesCount(); n++) {
        if (matrix[n][vertex]) {
            prevs.push_back(n);
        }
    }

    return prevs;
}
