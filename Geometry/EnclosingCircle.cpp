P perp(const P &a) {
    return P(-a.y, a.x);
}
struct Circle {
    P o;
    double r;
    inline bool in(const P &a) const { return (a - o).lth() <= r + eps; }
};
Circle getcircle(const P &a, const P &b) {
    return Circle{(a + b) / 2, (a - b).lth() / 2};
}
Circle getcircle(const P &a, const P &b, const P &c) {
    const P p1 = (a + b) / 2, p2 = (a + c) / 2;
    Circle res;
    res.o = intersection(p1, p1 + perp(a - b), p2, p2 + perp(a - c));
    res.r = (res.o - a).lth();
    return res;
}
Circle findcircle(vector<P> &ar) {
    int n = size(ar);
    shuffle(iter(ar), mt19937(time(NULL)));
    Circle res = {ar[0], 0};
    for (int i = 0; i < n; i++) {
        if (res.in(ar[i]))
            continue;
        res = {ar[i], 0};
        for (int j = 0; j < i; j++) {
            if (res.in(ar[j]))
                continue;
            res = getcircle(ar[i], ar[j]);
            for (int k = 0; k < j; k++) {
                if (res.in(ar[k]))
                    continue;
                res = getcircle(ar[i], ar[j], ar[k]);
            }
        }
    }
    return res;
}