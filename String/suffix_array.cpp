struct SA {
    static const int N = 5e5 + 5; // change
    int sa[N], rk[N], cnt[N], lcp[N], tmp[N], n;
    void blt(const string &s) {
        n = s.length();
        int m = 128;
        memset(cnt + 1, 0, m << 2);
        for (int i = 0; i < n; i++)
            cnt[rk[i] = s[i]]++;
        for (int i = 1; i <= m; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            sa[--cnt[rk[i]]] = i;
        for (int k = 1;; k <<= 1) {
            int ln = 0;
            for (int i = n - k; i < n; i++)
                tmp[ln++] = i;
            for (int i = 0; i < n; i++)
                if (sa[i] >= k)
                    tmp[ln++] = sa[i] - k;
            memset(cnt + 1, 0, m << 2);
            for (int i = 0; i < n; i++)
                cnt[rk[i]]++;
            for (int i = 1; i <= m; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--)
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            memcpy(tmp, rk, n << 2), rk[sa[0]] = m = 1;
            for (int i = 1; i < n; i++) {
                if (tmp[sa[i]] != tmp[sa[i - 1]] ||
                    tmp[sa[i] + k] != tmp[sa[i - 1] + k])
                    m++;
                rk[sa[i]] = m;
            }
            if (m == n)
                break;
        }
        for (int i = 0, k = 0; i < n; i++, k -= !!k) {
            if (rk[i] == n)
                continue;
            int j = sa[rk[i]];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            lcp[rk[i]] = k;
        } // lcp[1~n-1],sa[0~n-1]
    }
};