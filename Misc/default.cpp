// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define ml(a, b) ((1ll * (a) * (b)) % M)
#define tml(a, b) (a) = ((1ll * (a) * (b)) % M)
#define ad(a, b) ((0ll + (a) + (b)) % M)
#define tad(a, b) (a) = ((0ll + (a) + (b)) % M)
#define mi(a, b) ((0ll + M + (a) - (b)) % M)
#define tmi(a, b) (a) = ((0ll + M + (a) - (b)) % M)
#define tmin(a, b) (a) = min((a), (b))
#define tmax(a, b) (a) = max((a), (b))
#define iter(a) (a).begin(), (a).end()
#define riter(a) (a).rbegin(), (a).rend()
#define inin(a, b) memset((a), (b), sizeof(a))
#define cpy(a, b) memcpy((a), (b), sizeof(a))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define size(x) (int)x.size()
#define pb emplace_back
#define mpr make_pair
#define ls(i) ((i) << 1)
#define rs(i) ((i) << 1 | 1)
#define INF 0x3f3f3f3f
#define NIF 0xc0c0c0c0
#define eps 1e-9
#define F first
#define S second
#define AC cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long llt;
typedef unsigned long long ull;
typedef __int128_t lll;
typedef double dl;
typedef pair<int, int> pii;
typedef pair<dl, dl> pdd;
typedef pair<llt, llt> pll;
typedef pair<llt, int> pli;
typedef complex<dl> cd;
typedef complex<llt> cll;
// const int M = 998244353;

// random_device rm;
// mt19937 rg(rm());
// default_random_engine rg(rm());
// uniform_int_distribution<int> rnd(INT_MIN, INT_MAX);
// uniform_real_distribution<double> rd(0, M_PI);

void db() { cerr << "\n"; }
template <class T, class... U>
void db(T a, U... b) { cerr << a << " ", db(b...); }

inline char gc()
{
    const static int SZ = 1 << 16;
    static char buf[SZ], *p1, *p2;
    if (p1 == p2 && (p2 = buf + fread(p1 = buf, 1, SZ, stdin), p1 == p2))
        return -1;
    return *p1++;
}
void rd() {}
template <typename T, typename... U>
void rd(T &x, U &...y)
{
    x = 0;
    bool f = 0;
    char c = gc();
    while (!isdigit(c))
        f ^= !(c ^ 45), c = gc();
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
    f && (x = -x), rd(y...);
}

template <typename T>
void prt(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        prt(x / 10);
    putchar((x % 10) ^ 48);
}

signed main()
{
}