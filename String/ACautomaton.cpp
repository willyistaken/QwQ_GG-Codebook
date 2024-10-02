struct ACauto {
    const static int N = 2e5 + 5; // change
    int tr[26][N], fail[N], ctn = 1, cnt[N], endat[N], n;
    vector<int> top; // fail tree topological order
    inline void clr(int p) {
        fail[p] = cnt[p] = 0;
        for (int i = 0; i < 26; i++)
            tr[i][p] = 0;
    }
    inline int add(const string &s) {
        int cr = 1;
        string tmp;
        for (int c : s) {
            tmp += c;
            c -= 'a';
            if (!tr[c][cr])
                clr(tr[c][cr] = ++ctn);
            cr = tr[c][cr];
        }
        return cr;
    }
    void blt(const vector<string> &ar) {
        for (int i = 0; i < 26; i++)
            tr[i][0] = 1;
        clr(ctn = 1), n = size(ar);
        for (int i = 0; i < n; i++)
            endat[i] = add(ar[i]);
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int pr = q.front();
            q.pop();
            top.pb(pr);
            for (int i = 0; i < 26; i++) {
                int &cr = tr[i][pr];
                if (cr)
                    fail[cr] = tr[i][fail[pr]], q.push(cr);
                else
                    cr = tr[i][fail[pr]];
            }
        }
        reverse(iter(top));
    }
    void qry(const string &s) {
        int cr = 1;
        for (char c : s) // ways to walk
            cr = tr[c - 'a'][cr], cnt[cr]++;
        for (int i : top)
            cnt[fail[i]] += cnt[i];
    }
};