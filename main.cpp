#include <iostream>
#include <assert.h>
#include <algorithm>
#include <queue>
#include "listgraph.h"
#include "matrixgraph.h"
#include "setgraph.h"
#include "arcgraph.h"


using namespace std;

template <typename Graph>
void generalTests(string structName) {
    { // Инициализация
        IGraph* graph = new Graph(322);
        assert(graph->VerticesCount() == 322);
        delete graph;
    }
    { // Получение следующих вершин
        IGraph* graph = new Graph(4);
        graph->AddEdge(1, 0);
        graph->AddEdge(1, 2);
        vector<int> nexts = graph->GetNextVertices(1);
        assert(nexts.size() == 2);
        assert(find(nexts.begin(), nexts.end(), 0) != nexts.end());
        assert(find(nexts.begin(), nexts.end(), 2) != nexts.end());
        delete graph;
    }
    { // Получение предыдущих вершин
        IGraph* graph = new Graph(4);
        graph->AddEdge(0, 1);
        graph->AddEdge(2, 1);
        vector<int> prevs = graph->GetPrevVertices(1);
        assert(prevs.size() == 2);
        assert(find(prevs.begin(), prevs.end(), 0) != prevs.end());
        assert(find(prevs.begin(), prevs.end(), 2) != prevs.end());
        delete graph;
    }

    cout << "general tests for " << structName << ": OK" << endl;
}


// BFS
vector<int> layerSizes(IGraph* graph, int startVertex) {
    vector<int> layers;

    vector<bool> visited(graph->VerticesCount(), false);
    queue<pair<int, int>> vertexQueue;
    vertexQueue.push({startVertex, 1});
    while (!vertexQueue.empty()) {
        auto curVertLayer = vertexQueue.front();
        vertexQueue.pop();

        int curVert = curVertLayer.first;
        int curLayer = curVertLayer.second;
        if (visited[curVert]) continue;
        visited[curVert] = true;

        if (layers.size() < curLayer) layers.resize(curLayer, 0);
        layers[curLayer - 1]++;

        vector<int> nexts = graph->GetNextVertices(curVert);
        for (int v : nexts) vertexQueue.push({v, curLayer + 1});
    }

    return layers;
}


void copyTests() {
    { // Прогоняем по кругу один из графов
        IGraph* graph = new ListGraph(6);
        graph->AddEdge(0, 1);
        graph->AddEdge(0, 2);
        graph->AddEdge(1, 2);
        graph->AddEdge(1, 3);
        graph->AddEdge(2, 4);
        graph->AddEdge(3, 4);
        graph->AddEdge(4, 5);

        IGraph* graph1 = new MatrixGraph(*graph);
        IGraph* graph2 = new SetGraph(*graph1);
        delete graph1;
        graph1 = new ArcGraph(*graph2);
        delete graph2;
        graph2 = new ListGraph(*graph1);
        delete graph1;

        assert(graph->VerticesCount() == graph2->VerticesCount());

        // Проверка, что размеры слоев, полученные BFS на графах одинаковые
        auto ls_g1 = layerSizes(graph, 0);
        auto ls_g2 = layerSizes(graph2, 0);
        assert(ls_g1.size() == ls_g2.size());
        for (int i = 0; i < ls_g1.size(); i++) {
            assert(ls_g1[i] == ls_g2[i]);
        }

        delete graph;
        delete graph2;
    }

    cout << "copyTests OK" << endl; 
}


int main() {
    generalTests<ListGraph>("ListGraph");
    generalTests<MatrixGraph>("MatrixGraph");
    generalTests<SetGraph>("SetGraph");
    generalTests<ArcGraph>("ArcGraph");

    copyTests();

    return 0;
}

