struct LCT {
    static const int N = 4e5 + 5; // change
    int fa[N], ch[2][N], sz[N], sv[N];
#define gch(x) ((x) == ch[1][fa[x]])
#define nrt(x) ((x) == ch[gch(x)][fa[x]])
#define up(x) sz[x] = sz[ch[0][x]] + sz[ch[1][x]] + sv[x] + 1
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
        for (int f = fa[x]; nrt(x); rota(x), f = fa[x])
            if (nrt(f))
                rota(gch(x) ^ gch(f) ? x : f);
    }
    inline int acc(int x) {
        int p;
        for (p = 0; x; p = x, x = fa[x])
            splay(x), sv[x] += sz[ch[1][x]] - sz[p], ch[1][x] = p, up(x);
        return p;
    }
    inline int findroot(int x) {
        int cr = acc(x);
        while (ch[0][cr])
            cr = ch[0][cr];
        splay(cr);
        return cr;
    }
    void link(int x, int y) {
        int rt = findroot(y);
        acc(x), acc(rt);
        acc(y), splay(y);
        sv[y] += sz[x];
        fa[x] = y, up(y);
        acc(rt);
    }
    void cut(int x, int y) {
        int rt = findroot(y);
        acc(rt);
        acc(y), splay(y), splay(x);
        sv[y] -= sz[x];
        fa[x] = 0, up(y);
        acc(x), acc(rt);
    }
};