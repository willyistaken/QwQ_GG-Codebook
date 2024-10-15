namespace Treap {
    const int N = 2e5 + 5;
    struct node {
        int ky, sz, mn, mx, ln, rn;
        ll sum;
        bool tg;
        static node *pl;
        node() { sum = sz = 0, mx = ~INF, mn = INF; }
        inline void ini(int v) { sum = ky = mx = mn = v, sz = 1, ln = rn = tg = 0; }
        inline void upd(int v) {
            ky = mx = mn = v;
            sum = 1ll * v * sz;
            tg = 1;
        }
        inline void up() {
            sz = 1 + pl[ln].sz + pl[rn].sz;
            sum = mx = mn = ky;
            sum += pl[ln].sum + pl[rn].sum;
            tmax(mx, max(pl[ln].mx, pl[rn].mx));
            tmin(mn, min(pl[ln].mn, pl[rn].mn));
        }
        inline void down() { tg && (ln && (pl[ln].upd(ky), 0), rn && (pl[rn].upd(ky), 0)), tg = 0; }
    } pool[N];
    mt19937 rnd(time(0));
    node *node::pl = pool, *pl = pool;
    int ctp = 0;
    inline int nwnd(int v) {
        pl[++ctp].ini(v);
        return ctp;
    }
    int mg(int a, int b) {
        if (!a || !b)
            return a ? a : b;
        if ((int)rnd() % (pl[a].sz + pl[b].sz) < pl[a].sz)
            return pl[a].down(), pl[a].rn = mg(pl[a].rn, b), pl[a].up(), a;
        else
            return pl[b].down(), pl[b].ln = mg(a, pl[b].ln), pl[b].up(), b;
    }
    void splsz(int rt, int &a, int &b, int k) {
        if (!rt)
            return a = b = 0, void();
        pl[rt].down();
        if (pl[pl[rt].ln].sz < k)
            a = rt, splsz(pl[rt].rn, pl[a].rn, b, k - pl[pl[rt].ln].sz - 1);
        else
            b = rt, splsz(pl[rt].ln, a, pl[b].ln, k);
        pl[rt].up();
    }
    void splky(int rt, int &a, int &b, int v) {
        if (!rt)
            return a = b = 0, void();
        pl[rt].down();
        if (pl[rt].ky <= v)
            a = rt, splky(pl[rt].rn, pl[a].rn, b, v);
        else
            b = rt, splky(pl[rt].ln, a, pl[b].ln, v);
        pl[rt].up();
    }
}
