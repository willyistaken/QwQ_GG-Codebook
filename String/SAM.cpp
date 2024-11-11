struct SAM {
    static const int N = 2e5 + 6;
    int tr[26][N], len[N], lnk[N], tmp[N], pl[N], ctn, lst;
    inline void ini(int x) {
        for (int i = 0; i < 26; i++)
            tr[i][x] = 0;
    }
    inline void ini() {
        ini(ctn = lst = len[0] = 0), lnk[0] = -1;
		memset(tmp,0,sizeof(tmp));
    }
    inline void cp(int x, int y) {
        lnk[x] = lnk[y];
        for (int i = 0; i < 26; i++)
            tr[i][x] = tr[i][y];
    }
    void ext(const char cc) {
        static int c, cr, p, q;
        c = cc - 'a', p = lst;
        ini(cr = ++ctn), len[cr] = len[p] + 1;
        while (~p && !tr[c][p])
            tr[c][p] = cr, p = lnk[p];
        if (~p) {
            q = tr[c][p];
            if (len[q] == len[p] + 1)
                lnk[cr] = q;
            else {
                cp(++ctn, q), len[ctn] = len[p] + 1;
                while (~p && tr[c][p] == q)
                    tr[c][p] = ctn, p = lnk[p];
                lnk[cr] = lnk[q] = ctn;
            }
        } else
            lnk[cr] = 0;
        lst = cr;
    }
    void blt(const string &s) {
        ini();
        for (const char &c : s)
            ext(c);
        for (int i = 0; i <= ctn; i++)
            tmp[len[i]]++;
        for (int i = 1; i <= ctn; i++)
            tmp[i] += tmp[i - 1];
        for (int i = ctn; i >= 0; i--)
            pl[--tmp[len[i]]] = i;
    }
};
