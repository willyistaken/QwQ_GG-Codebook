#include <algorithm>
#include <assert.h>
#include <bitset>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define init(a, b) memset((a), (b), sizeof(a))
#define cpy(a, b) memcpy((a), (b), sizeof(a))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define pb push_back
#define mpr make_pair
#define ls(i) ((i) << 1)
#define rs(i) ((i) << 1 | 1)
#define INF 0x3f3f3f3f
#define eps 1e-9
#define F first
#define S second
#define N 2005
#define AC cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long llt;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llt, llt> pll;
typedef complex<double> cd;
// const int M = 998244353;

// random_device rm;
// mt19937 rg(rm());
// default_random_engine rg(rm());
// uniform_int_distribution<int> rd(INT_MIN, INT_MAX);
// uniform_real_distribution<double> rd(0, M_PI);

pll operator-(const pll &a, const pll &b) {
    return mpr(a.F - b.F, a.S - b.S);
}

llt operator^(const pll &a, const pll &b) {
    return a.F * b.S - a.S * b.F;
}

bool ud(const pll &a) {
    if (!a.S)
        return a.F > 0;
    return a.S > 0;
}

bool cmp(const pll &a, const pll &b) {
    if (ud(a) ^ ud(b))
        return ud(a);
    return (a ^ b) > 0;
}

pll ar[N];
pii lr[N * N];
int id[N], po[N];
vector<int> an;

signed main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &ar[i].F, &ar[i].S);
    if (n > 2) {
        int m = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    lr[m++] = mpr(i, j);
        sort(lr, lr + m, [&](const pii &a, const pii &b) { return cmp(ar[a.F] - ar[a.S], ar[b.F] - ar[b.S]); });
        iota(id, id + n, 0);
        sort(id, id + n, [&](int a, int b) { return ar[a].S == ar[b].S ? ar[a].F < ar[b].F : ar[a].S < ar[b].S; });
        int cr = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (id[i] > id[j])
                    cr++;
        for (int i = 0; i < n; i++)
            po[id[i]] = i;
        for (int i = 0; i < m; i++) {
            if ((po[lr[i].F] < po[lr[i].S]) ^ (lr[i].F < lr[i].S))
                cr--;
            else
                cr++;
            swap(id[po[lr[i].F]], id[po[lr[i].F]]), swap(po[lr[i].F], po[lr[i].S]);
            if (i == m - 1)
                an.pb(cr);
            else if (((ar[lr[i].F] - ar[lr[i].S]) ^ (ar[lr[i + 1].F] - ar[lr[i + 1].S])) != 0)
                an.pb(cr);
        }
    } else
        an.pb(0), an.pb(1);
    sort(riter(an));
    int q, x;
    scanf("%d", &q);
    while (q-- && scanf("%d", &x))
        printf("%d\n", an[x - 1]);
}