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