Variacion del BFS para hallar la distancia minima para aristas donde los unicos pesos posibles son x, x+1.
En caso tal de x=0 se puede reemplazar q0 y q1 por una bicola.

typedef pair<int,int> pii;
const int N = 1e5+5, inf = 1e9;
vector<pii> g(N); //se guarda nodo y peso de la arista
vector<int> dist(N, inf);
vector<bool> visited(N, false);
int n, m;

void bfs_01(int source) {
    dist[source] = 0;
    vector<int> q0, q1;
    q0.push_back(source);
    while (!q0.empty()) {
        int v = q0.back();
        q0.pop_back();
        for (auto edge : g[v]) {
            int u = edge.first;
            int w = edge.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                if (w == 0)
                    q0.push_back(u);
                else
                    q1.push_back(u);
            }
        }
        if (q0.empty())
            swap(q0, q1);
    }
}

void init() {
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        dist[i] = inf;
        visited[i] = false;
    }
}