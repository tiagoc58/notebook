Segmentree iterativo para optimizar la velocidad de las operaciones, el problema es que no permite combinar
las range queries con las range updates, por lo que solo se puede tener una y por ende la otra debera ser puntual.
Esta implementacion sirve para plantillas como heavy ligth descomposition.

struct iterativetree {
    int n;
    vector<int> t;

    iterativetree(vector<int> &v) {
        n = v.size();
        t.assign(2*n);
        for (int i = 0; i < n; i++) t[i+n] = v[i];
        for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
    }

    // RANGE QUERIES & SINGLE UPDATE
    int query(int l, int r) {  // [l, r]
        int res = 0;
        for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += t[l++];
            if (r&1) res += t[--r];
        }
        return res;
    }

    void upd(int p, int value) {  // actualiza el valor en la posicion p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    }

    // si va usar esta borre los dos metodos de arriba y quitele los comentarios a los 2 de abajo
    // RANGE UPDATES & SINGLE QUERY
    // int query(int p) { // retorna el valor en la posicion p
    //     int res = 0;
    //     for (p += n; p > 0; p >>= 1) res += t[p];
    //     return res;
    // }
    //
    // void upd(int l, int r, int value) {  // [l, r]
    //     for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
    //         if (l&1) t[l++] += value;
    //         if (r&1) t[--r] += value;
    //     }
    // }
};

