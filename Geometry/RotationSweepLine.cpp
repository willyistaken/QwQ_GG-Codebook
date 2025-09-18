// int cmp1(const P &a, const P &b) {
//     bool ba = updown(a - BASE), bb = updown(b - BASE);
//     if (ba ^ bb)
//         return ba - !ba;
//     return ori(BASE, a, b);
// }
// Collinear
void sweep(int n, vector<P> ar) {
    static const int N = 2005;
    static int id[N], po[N];
    static pii lr[N * N];
    int m = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                lr[m++] = pii(i, j);
    sort(lr, lr + m, [&](const pii &a, const pii &b) { return cmp(ar[a.first] - ar[a.second], ar[b.first] - ar[b.second]); });
    // sort(lr, lr + m, [&](const pii &a, const pii &b) {
    //     int tmp = cmp1(ar[a.first] - ar[a.second], ar[b.first] - ar[b.second]);
    //     if (tmp)
    //         return tmp > 0;
    //     if (ar[a.first] != ar[b.first])
    //         return ar[a.first] < ar[b.first];
    //     return ar[a.second] < ar[b.second];
    // });
    iota(id, id + n, 0);
    sort(id, id + n, [&](int a, int b) { return ar[a].y == ar[b].y ? ar[a].x < ar[b].x : ar[a].y < ar[b].y; });
    for (int i = 0; i < n; i++)
        po[id[i]] = i;
    for (int i = 0; i < m; i++) {
        swap(id[po[lr[i].first]], id[po[lr[i].second]]), swap(po[lr[i].first], po[lr[i].second]);
    }
}