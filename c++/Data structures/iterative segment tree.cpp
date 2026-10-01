Segmentree iterativo para optimizar la velocidad de las operaciones, el problema es que no permite combinar
las range queries con las range updates, por lo que solo se puede tener una y por ende la otra debera ser puntual.
Esta implementacion sirve para plantillas como heavy ligth descomposition.

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}


// RANGE QUERIES & SINGLE UPDATE
void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // [l, r]
    int res = 0;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

// RANGE UPDATES & SINGLE QUERY
void modify(int l, int r, int value) {  // [l, r]
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l&1) t[l++] += value;
        if (r&1) t[--r] += value;
    }
}

int query(int p) {
    int res = 0;
    for (p += n; p > 0; p >>= 1) res += t[p];
    return res;
}