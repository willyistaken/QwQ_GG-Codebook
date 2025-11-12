struct LCT {
    static const int N = 4e5 + 5; // change
    int fa[N], ch[2][N];
    ll sz[N], sv[N];
    bool rtg[N];
#define gch(x) ((x) == ch[1][fa[x]])
#define nrt(x) ((x) == ch[gch(x)][fa[x]])
#define up(x) sz[x] = sz[ch[0][x]] + sz[ch[1][x]] + sv[x]
#define rev(x) swap(ch[0][x], ch[1][x]), rtg[x] ^= 1
#define down(x) rtg[x] && (rev(ch[0][x]), rev(ch[1][x])), rtg[x] = 0
    void adown(int x) {
        if (nrt(x))
            adown(fa[x]);
        down(x);
    }
    inline void rota(int x) {
        int f = fa[x], ff = fa[f], k = gch(x);
        if (nrt(f))
            ch[gch(f)][ff] = x;
        fa[x] = ff;
        if (ch[!k][x])
            fa[ch[!k][x]] = f;
        ch[k][f] = ch[!k][x];
        ch[!k][x] = f, fa[f] = x;
        up(f), up(x);
    }
    inline void splay(int x) {
        if (!x)
            return;
        adown(x);
        for (int f = fa[x]; nrt(x); rota(x), f = fa[x])
            if (nrt(f))
                rota(gch(x) ^ gch(f) ? x : f);
    }
    inline int acc(int x) {
        int p;
        for (p = 0; x; p = x, x = fa[x])
            splay(x), ch[1][x] = p, up(x);
        return p;
    }
    inline void mkrt(int x) {
        int p = acc(x);
        rev(p);
    }
    inline void link(int x, int y) {
        mkrt(x), splay(x), fa[x] = y;
    }
    inline void cut(int x, int y) {
        mkrt(x), acc(y), splay(y);
        fa[x] = 0, ch[0][y] = 0, up(y);
    }
    inline void ini(int x, int v) {
        rtg[x] = fa[x] = ch[0][x] = ch[1][x] = 0;
        sz[x] = sv[x] = v;
    }
};