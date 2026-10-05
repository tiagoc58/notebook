Metodo para girar una matriz 45 grados, esto sirve especialmente para problemas de prefixsum 2D de distancias
Manhattan (UVA 1105)

void transform_coords(int x, int y, int &u, int &v) {
    u = x + y;
    v = x - y + dy;
}

void solve() {
    int max_u = dx + dy;
    int max_v = dx + dy;
    int grid[max_u][max_v];
}