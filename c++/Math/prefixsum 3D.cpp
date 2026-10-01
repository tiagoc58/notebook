metodos para encontrar el prefixsum en una matriz de 3 dimensiones y la suma en el subcubo indicado

typedef long long ll;
vector<vector<vector<ll>>> prefixSum3d(vector<vector<vector<ll>>> &A) {
    int n = A.size(), m = A[0].size(), r = A[0][0].size();
    vector<vector<vector<ll>>> pre(n, vector<vector<ll>>(m, vector<ll>(r)));

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int z = 0; z < r; z++) {
                pre[x][y][z] = A[x][y][z];

                if (x > 0)
                    pre[x][y][z] += pre[x-1][y][z];

                if (y > 0)
                    pre[x][y][z] += pre[x][y-1][z];

                if (z > 0)
                    pre[x][y][z] += pre[x][y][z-1];

                if (x > 0 && y > 0)
                    pre[x][y][z] -= pre[x-1][y-1][z];

                if (x > 0 && z > 0)
                    pre[x][y][z] -= pre[x-1][y][z-1];

                if (y > 0 && z > 0)
                    pre[x][y][z] -= pre[x][y-1][z-1];

                if (x > 0 && y > 0 && z > 0)
                    pre[x][y][z] += pre[x-1][y-1][z-1];
            }
        }
    }

    return pre;
}

ll query(vector<vector<vector<ll>>> &pre,int x1, int y1, int z1,int x2, int y2, int z2) {
    ll ans = pre[x2][y2][z2];

    if (x1 > 0)
        ans -= pre[x1-1][y2][z2];

    if (y1 > 0)
        ans -= pre[x2][y1-1][z2];

    if (z1 > 0)
        ans -= pre[x2][y2][z1-1];

    if (x1 > 0 && y1 > 0)
        ans += pre[x1-1][y1-1][z2];

    if (x1 > 0 && z1 > 0)
        ans += pre[x1-1][y2][z1-1];

    if (y1 > 0 && z1 > 0)
        ans += pre[x2][y1-1][z1-1];

    if (x1 > 0 && y1 > 0 && z1 > 0)
        ans -= pre[x1-1][y1-1][z1-1];

    return ans;
}