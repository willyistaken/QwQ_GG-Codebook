const int mod = 1000000007;
 
inline int madd(int u, int v)
{
    u += v - mod;
    u += mod & (u >> 31);
    return u;
}
 
inline int mmul(int u, int v)
{
    return (ll)u * v % mod;
}
 
inline int pwr(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = mmul(a, a))
        if (b & 1)
            ret = mmul(ret, a);
    return ret;
}
 
inline int inv(int x) { return pwr(x, mod - 2); }
 
void xormul(vector<int> a, vector<int> b, vector<int> &c)
{
    int m = size(a);
    c.resize(m);
    for (int n = m / 2; n > 0; n /= 2)
        for (int i = 0; i < m; i += 2 * n)
            for (int j = 0; j < n; j++)
            {
                int x = a[i + j], y = a[i + j + n];
                a[i + j] = madd(x, y);
                a[i + j + n] = madd(x, mod - y);
            }
    for (int n = m / 2; n > 0; n /= 2)
        for (int i = 0; i < m; i += 2 * n)
            for (int j = 0; j < n; j++)
            {
                int x = b[i + j], y = b[i + j + n];
                b[i + j] = madd(x, y);
                b[i + j + n] = madd(x, mod - y);
            }
    for (int i = 0; i < m; i++)
        c[i] = mmul(a[i], b[i]);
    for (int n = 1; n < m; n *= 2)
        for (int i = 0; i < m; i += 2 * n)
            for (int j = 0; j < n; j++)
            {
                int x = c[i + j], y = c[i + j + n];
                c[i + j] = madd(x, y);
                c[i + j + n] = madd(x, mod - y);
            }
    int mrev = inv(m);
    for (int i = 0; i < m; i++)
        c[i] = mmul(c[i], mrev);
}
