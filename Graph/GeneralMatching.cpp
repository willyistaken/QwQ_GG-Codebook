struct Matching {
    static const int maxn = 505, p = (int)1e9 + 7;// change this, 1-base
    int sizen = 0;
    int sub_n=0;
    int id[maxn], vertices[maxn], matches[maxn];
    bool row_marked[maxn] = {false}, col_marked[maxn] = {false};
    int A[maxn][maxn], B[maxn][maxn], t[maxn][maxn];
    vector<pair<int,int> > sidearr;
    void init(int _n) {
        sizen = _n;
        sub_n = 0;
        fill(id,id+_n+1,0);
        fill(vertices,vertices+_n+1,0);
        fill(matches,matches+_n+1,0);
        fill(row_marked,row_marked+_n+1,0);
        fill(col_marked,col_marked+_n+1,0);
        for(int i=0; i<=_n; i++) {
            fill(A[i],A[i]+_n+1,0);
            fill(B[i],B[i]+_n+1,0);
            fill(t[i],t[i]+_n+1,0);
        }
        sidearr.clear();
    }
    Matching(int _n) {
        init(_n);
    }
    int qpow(int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = (long long)ans * a % p;
            a = (long long)a * a % p;
            b >>= 1;
        }
        return ans;
    }
    void Gauss(int A[][maxn], int B[][maxn], int n) {
        if (B) {
            memset(B, 0, sizeof(t));
            for (int i = 1; i <= n; i++) B[i][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (!A[i][i]) {
                for (int j = i + 1; j <= n; j++) {
                    if (A[j][i]) {
                        swap(id[i], id[j]);
                        for (int k = i; k <= n; k++) swap(A[i][k], A[j][k]);
                        if (B) for (int k = 1; k <= n; k++) swap(B[i][k], B[j][k]);
                        break;
                    }
                }
                if (!A[i][i]) continue;
            }
            int inv = qpow(A[i][i], p - 2);
            for (int j = 1; j <= n; j++) {
                if (i != j && A[j][i]) {
                    int t = (long long)A[j][i] * inv % p;
                    for (int k = i; k <= n; k++) if (A[i][k]) A[j][k] = (A[j][k] - (ll)t * A[i][k]) % p;
                    if (B) {
                        for (int k = 1; k <= n; k++) if (B[i][k]) B[j][k] = (B[j][k] - (ll)t * B[i][k]) % p;
                    }
                }
            }
        }
        if (B) {
            for (int i = 1; i <= n; i++) {
                int inv = qpow(A[i][i], p - 2);
                for (int j = 1; j <= n; j++) {
                    if (B[i][j]) B[i][j] = (long long)B[i][j] * inv % p;
                }
            }
        }
    }
    void eliminate(int r, int c) {
        row_marked[r] = col_marked[c] = true;
        int inv = qpow(B[r][c], p - 2);
        for (int i = 1; i <= sub_n; i++) {
            if (!row_marked[i] && B[i][c]) {
                int t = (long long)B[i][c] * inv % p;

                for (int j = 1; j <= sub_n; j++)
                    if (!col_marked[j] && B[r][j])
                        B[i][j] = (B[i][j] - (long long)t * B[r][j]) % p;
            }
        }
    }
    void add_edge(int a,int b) {
        sidearr.push_back({min(a,b),max(a,b)});
    }
    void build_matching() {
        auto rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
        for(auto e : sidearr) {
            int x = e.first;
            int y = e.second;
            A[x][y] = rng() % p;
            A[y][x] = -A[x][y];
        }
        for (int i = 1; i <= sizen; i++) id[i] = i;
        memcpy(t, A, sizeof(t));
        Gauss(A, nullptr, sizen);
        for (int i = 1; i <= sizen; i++) {
            if (A[id[i]][id[i]]) vertices[++sub_n] = i;
        }
        for (int i = 1; i <= sub_n; i++) {
            for (int j = 1; j <= sub_n; j++) A[i][j] = t[vertices[i]][vertices[j]];
        }
        Gauss(A, B, sub_n);
        for (int i = 1; i <= sub_n; i++) {
            if (!matches[vertices[i]]) {
                for (int j = i + 1; j <= sub_n; j++) {
                    if (!matches[vertices[j]] && t[vertices[i]][vertices[j]] && B[j][i]) {
                        matches[vertices[i]] = vertices[j];
                        matches[vertices[j]] = vertices[i];
                        eliminate(i, j);
                        eliminate(j, i);
                        break;
                    }
                }
            }
        }
    }
    int matched(int x) {
        return matches[x];
    }
};
