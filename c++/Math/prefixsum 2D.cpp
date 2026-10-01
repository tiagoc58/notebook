metodos para encontrar el prefixsum en una matriz de 2 dimensiones y la suma en el subrectangulo indicado

typedef long long ll;
vector<vector<ll>> prefixSum2d(vector<vector<ll>> &A) {
    int n = A.size(), m = A[0].size();

    vector<vector<ll>> pre(n, vector<ll>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            pre[i][j] = A[i][j];

            if (i > 0)
                pre[i][j] += pre[i-1][j];

            if (j > 0)
                pre[i][j] += pre[i][j-1];

            if (i > 0 && j > 0)
                pre[i][j] -= pre[i-1][j-1];
        }
    }

    return pre;
}

ll query(vector<vector<ll>> &pre,int x1, int y1,int x2, int y2) {
    ll ans = pre[x2][y2];

    if (x1 > 0)
        ans -= pre[x1-1][y2];

    if (y1 > 0)
        ans -= pre[x2][y1-1];

    if (x1 > 0 && y1 > 0)
        ans += pre[x1-1][y1-1];

    return ans;
}