#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> Grafo;

pair<int, int> Dijkstra(int og, int end) {
    vector<pair<int, int>> distance(Grafo.size(), make_pair(INF, INF));  
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> adyacentes;  // ((distancia, numero de calles), nodo)
    
    adyacentes.push(make_pair(make_pair(0, 0), og)); 
    distance[og] = make_pair(0, 0); 

    while (!adyacentes.empty()) {
        pair<pair<int, int>, int> pr = adyacentes.top();
        adyacentes.pop();
        int coste = pr.first.first, calles = pr.first.second, v = pr.second;

        if (coste > distance[v].first) continue;  

        for (pair<int, int> w : Grafo[v]) {
            int wp = w.second, cos = w.first;

            if (cos + coste < distance[wp].first || (cos + coste == distance[wp].first && calles + 1 < distance[wp].second)) {
                distance[wp] = make_pair(cos + coste, calles + 1);
                adyacentes.push(make_pair(make_pair(cos + coste, calles + 1), wp));
            }
        }
    }

    return distance[end];
}

int BFS(int og, int end) {
    vector<int> distance(Grafo.size(), -1); 
    queue<int> adyacentes;
    adyacentes.push(og);
    distance[og] = 0;

    while (!adyacentes.empty()) {
        int v = adyacentes.front();
        adyacentes.pop();

        for (pair<int, int> wp : Grafo[v]) {
            int w = wp.second;
            if (distance[w] == -1) {  
                distance[w] = distance[v] + 1;
                adyacentes.push(w);
            }
        }
    }

    return distance[end]; 
}

bool solve() {
    int V, A;
    cin >> V >> A;
    if (!cin) return false;

    Grafo.assign(V + 1, vector<pair<int, int>>());
    for (int i = 0; i < A; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        Grafo[u].push_back(make_pair(c, v));
        Grafo[v].push_back(make_pair(c, u));
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int o, d;
        cin >> o >> d;
        pair<int, int> res = Dijkstra(o, d);
        int bfs = BFS(o, d);

        if (bfs == -1) {
            cout << "SIN CAMINO\n";
        } else {
            cout << res.first << ' ' << (res.second == bfs ? "SI\n" : "NO\n");
        }
    }

    cout << "----\n";
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (solve());
    return 0;
}
