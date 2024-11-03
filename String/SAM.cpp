struct SAM {
    static const int N = 1e6 + 6;
    int tr[26][N], len[N], link[N], ctn, lst;
    inline void ini(int x) {
        for (int i = 0; i < 26; i++)
            tr[i][x] = 0;
    }
    inline void ini() {
        ini(ctn = lst = len[0] = 0), link[0] = -1;
    }
    inline void cp(int x, int y) {
        link[x] = link[y];
        for (int i = 0; i < 26; i++)
            tr[i][x] = tr[i][y];
    }
    void ext(const char cc) {
        static int c, cr, p, q;
        c = cc - 'a', p = lst;
        ini(cr = ++ctn), len[cr] = len[p] + 1;
        while (~p && !tr[c][p])
            tr[c][p] = cr, p = link[p];
        if (~p) {
            q = tr[c][p];
            if (len[q] == len[p] + 1)
                link[cr] = q;
            else {
                cp(++ctn, q), len[ctn] = len[p] + 1;
                while (~p && tr[c][p] == q)
                    tr[c][p] = ctn, p = link[p];
                link[cr] = link[q] = ctn;
            }
        } else
            link[cr] = 0;
        lst = cr;
    }
    void blt(const string &s) {
        ini();
        for (const char &c : s)
            ext(c);
    }
};