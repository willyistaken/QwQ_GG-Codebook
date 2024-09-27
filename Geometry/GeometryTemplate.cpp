struct P {
#define eps 1e-9
    double x, y;
    P() { x = y = 0; }
    P(double x, double y) : x(x), y(y) {}
    friend bool operator<(const P &a, const P &b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
    friend bool operator<=(const P &a, const P &b) { return a.x == b.x ? a.y <= b.y : a.x <= b.x; }
    friend bool operator==(const P &a, const P &b) { return a.x == b.x && a.y == b.y; }
    friend bool operator!=(const P &a, const P &b) { return a.x != b.x || a.y != b.y; }
    P operator+(const P &b) const { return P(x + b.x, y + b.y); }
    void operator+=(const P &b) { x += b.x, y += b.y; }
    P operator-(const P &b) const { return P(x - b.x, y - b.y); }
    void operator-=(const P &b) { x -= b.x, y -= b.y; }
    P operator*(double b) const { return P(x * b, y * b); }
    void operator*=(double b) { x *= b, y *= b; }
    P operator/(double b) const { return P(x / b, y / b); }
    void operator/=(double b) { x /= b, y /= b; }
    double operator*(const P &b) const { return x * b.x + y * b.y; }
    double operator^(const P &b) const { return x * b.y - y * b.x; }
    double lth() const { return sqrt(x * x + y * y); }
    double lth2() const { return x * x + y * y; }
    inline void print() { cout << '(' << x << ' ' << y << ')'; }
    friend istream &operator>>(istream &is, P &a) { return is >> a.x >> a.y; }
    friend ostream &operator<<(ostream &os, const P &a) { return os << a.x << ' ' << a.y; }
};
int ori(const P &a, const P &b, const P &c) {
    double k = (b - a) ^ (c - a);
    if (fabs(k) < eps)
        return 0;
    return k > 0 ? 1 : -1;
}
inline bool within(const P &a, const P &b, const P &c) {
    return (b - a) * (c - a) < eps;
}
bool intersects(const P &a, const P &b, const P &c, const P &d) {
    int abc = ori(a, b, c);
    int abd = ori(a, b, d);
    int cda = ori(c, d, a);
    int cdb = ori(c, d, b);
    if (!abc && !abd)
        return within(a, c, d) || within(b, c, d) ||
               within(c, a, b) || within(d, a, b);
    return abc * abd <= 0 && cda * cdb <= 0;
}
P intersection(const P &a, const P &b, const P &c, const P &d) {
    double abc = (b - a) ^ (c - a);
    double abd = (b - a) ^ (d - a);
    return (d * abc - c * abd) / (abc - abd);
}
P BASE(0, 0);
inline bool updown(const P &a) {
    if (fabs(a.y) < eps)
        return a.x > eps;
    return a.y > eps;
}
bool cmp(const P &a, const P &b) {
    bool ba = updown(a - BASE), bb = updown(b - BASE);
    if (ba ^ bb)
        return ba;
    return ori(BASE, a, b) > 0;
}
void fdhl(vector<P> &ar, vector<P> &hl) {
    for (int i = 0; i < 2; i++) {
        int prln = hl.size();
        for (int j = 0; j < size(ar); j++) {
            while (size(hl) - prln > 1 && ori(hl[size(hl) - 1], hl[size(hl) - 2], ar[j]) >= 0)
                hl.pop_back();
            hl.push_back(ar[j]);
        }
        if (hl.size() > 1)
            hl.pop_back();
        reverse(ar.begin(), ar.end());
    }
    if (hl.size() > 1 && hl.front() == hl.back())
        hl.pop_back();
}
bool in(const P &a, vector<P> &hl) {
    int ln = hl.size();
    if (ln == 1)
        return a == hl[0];
    if (ln == 2)
        return within(a, hl[0], hl[1]);
    int l = 1, r = ln - 1, m;
    while (l < r - 1) {
        m = (l + r) >> 1;
        if (ori(hl[0], a, hl[m]) < 0)
            l = m;
        else
            r = m;
    }
    return ori(hl[0], hl[l], a) >= 0 && ori(hl[l], hl[r], a) >= 0 && ori(hl[r], hl[0], a) >= 0;
}