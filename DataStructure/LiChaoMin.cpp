struct LiChaoMin {
    struct line {
        ll m, k, id;
        line(ll _m = 0, ll _k = 0, ll _id = 0) : m(_m), k(_k), id(_id) {}
        ll at(ll x) { return m * x + k; }
    };
    struct node {
        node *l, *r;
        line f;
        node(line v) : f(v), l(NULL), r(NULL) {}
    };
    node *root;
    int sz;
    void insert(node *&x, int l, int r, line &ln) {
        if (!x) {
            x = new node(ln);
            return;
        }
        ll trl = x->f.at(l), trr = x->f.at(r);
        ll vl = ln.at(l), vr = ln.at(r);
        if (trl <= vl && trr <= vr)
            return;
        if (trl > vl && trr > vr) {
            x->f = ln;
            return;
        }
        if (trl > vl)
            swap(x->f, ln);
        int mid = (l + r) >> 1;
        if (x->f.at(mid) < ln.at(mid))
            insert(x->r, mid + 1, r, ln);
        else
            swap(x->f, ln), insert(x->l, l, mid, ln);
    }
    ll query(node *&x, int l, int r, ll idx) {
        if (!x)
            return LONG_LONG_MAX;
        if (l == r)
            return x->f.at(idx);
        int mid = (l + r) >> 1;
        if (mid >= idx)
            return min(x->f.at(idx), query(x->l, l, mid, idx));
        return min(x->f.at(idx), query(x->r, mid + 1, r, idx));
    }
    LiChaoMin(int _sz) : sz(_sz + 1), root(NULL) {}
    void add_line(ll m, ll k, ll id = 0) {
        auto ln = line(m, k, id);
        insert(root, -sz, sz, ln);
    } // -sz <= query_x <= sz
    ll query(ll idx) { return query(root, -sz, sz, idx); }
};
