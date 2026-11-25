#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        if (weight != other.weight)
            return weight < other.weight;
        if (u != other.u)
            return u < other.u;
        return v < other.v;
    }
};

// Система неперетинних множин (DSU) для перевірки циклів
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int main() {
    int n = 11; // Кількість вершин у графі варіанта 7
    vector<Edge> edges = {
        {1, 2, 1}, {1, 3, 2}, {1, 4, 4},
        {2, 5, 7}, {2, 6, 5}, {3, 5, 2}, {4, 6, 2}, {4, 7, 3},
        {5, 8, 4}, {5, 9, 7}, {6, 8, 3}, {6, 10, 2}, {7, 9, 2}, {7, 10, 4},
        {8, 11, 7}, {9, 11, 1}, {10, 11, 5}
    };

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<Edge> mst;
    int totalWeight = 0;

    cout << "Етапи побудови мiнiмального остового дерева (алгоритм Краскала):\n";
    cout << "-----------------------------------------------------------------\n";

    int step = 1;
    for (const auto& edge : edges) {
        cout << "Крок " << step++ << ": розгляд ребра (" << edge.u << ", " << edge.v 
             << ") з вагою " << edge.weight << " -> ";
        
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            cout << "ДОДАНО до остового дерева.\n";
        } else {
            cout << "ВIДХИЛЕНО (утворює цикл).\n";
        }

        if (mst.size() == n - 1) break;
    }

    cout << "\nРебра мiнiмального остового дерева:\n";
    for (const auto& e : mst) {
        cout << "(" << e.u << ", " << e.v << ") [вага: " << e.weight << "]\n";
    }
    cout << "Загальна вага МОД: " << totalWeight << endl;

    return 0;
}