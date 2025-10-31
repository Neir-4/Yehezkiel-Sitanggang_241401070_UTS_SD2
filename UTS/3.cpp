#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    vector<string> kafe = {"Warung Kopi Pak Harry","Kedai Coding IKLC","Caffe Alya",
        "Studio Fasilkom-TI","Wi-Fi Gratis Sejagat",
    };
    vector<char> huruf = {'A','B','C','D','E',
    };

    void addEdge(int i, int j, int w) {
        i--;
        j--;
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = w;
            adjMatrix[j][i] = w;
        } else {
            cout << "Indeks simpul tidak valid." << endl;
        }
    }

    // ----- BAGIAN DFS -----
    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "PENJELAJAHAN PARUL (DFS dari " << huruf[startVertex] << "):" << endl;
        dfsUtil(startVertex, visited);

        cout << endl;
    }

    void dfsUtil(int currentVertex, vector<bool>& visited) {
        visited[currentVertex] = true;
        cout << huruf[currentVertex];
        for (int i = numVertices - 1; i >= 0; i--) {
            if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                cout << " -> ";
                dfsUtil(i, visited);
            }
        }
    }
    
    // ----- BAGIAN BFS -----
    void bfs(int startVertex, int endVertex) {
        vector<bool> visited(numVertices, false);
        vector<int> parent(numVertices, -1);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int current = q.front(); 
            q.pop();
            vector<pair<int,int>> tetangga; 
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[current][i] != 0 && !visited[i]) {
                    tetangga.push_back({adjMatrix[current][i], i});
                }
            }
            sort(tetangga.begin(), tetangga.end()); 
            for (auto &p : tetangga) {
                int i = p.second;
                if (!visited[i]) {
                    visited[i] = true;
                    parent[i] = current;
                    q.push(i);
                    if (i == endVertex) break;
                }
            }
        }

        vector<int> jalur;
        for (int v = endVertex; v != -1; v = parent[v]) {
            jalur.push_back(v);
        }
        reverse(jalur.begin(), jalur.end());

        cout << "JALUR TERCEPAT PARUL (BFS):\n";
        int totalJarak = 0;
        for (size_t i = 0; i < jalur.size(); i++) {
            cout << kafe[jalur[i]] << " (" << huruf[jalur[i]] << ")\n";
            if (i < jalur.size() - 1) {
                int w = adjMatrix[jalur[i]][jalur[i+1]];
                cout << w << "m\n";
                totalJarak += w;
            }
        }

        cout << "\nJalur terpendek: ";
        for (size_t i = 0; i < jalur.size(); i++) {
            cout << huruf[jalur[i]];
            if (i < jalur.size() - 1) cout << " -> ";
        }
        cout << "\nTotal langkah: " << jalur.size() - 1 << " edge";
        cout << "\nTotal jarak: " << totalJarak << " meter";
        cout << endl;
    }



};

int main() {
    system("cls");
    Graph g(6);
    g.addEdge(1,2,4);
    g.addEdge(1,3,2);
    g.addEdge(2,4,3);
    g.addEdge(3,4,1);
    g.addEdge(4,5,5);

    g.dfs(0);
    cout << endl;
    g.bfs(0, 4);
    return 0;
}