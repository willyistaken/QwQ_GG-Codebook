int mod_log(int a, int b, int m) {
	if(b==1%m) return 0;
    int n = int(ceil(sqrt(m)));
    int e = 0;
    int k = 1;
    for (int g; (g = gcd(a, m)) != 1;) {
        if (b % g != 0) return -1;
        b /= g; m /= g;
        e++;
		k = (1LL*k*(a/g))%m;
        if (b == k) return e;
    }
    int x = 1;
    unordered_map<int, int> map_;
    for (int q = 0; q < n; q++, x = (1LL*x*a)%m) {
        map_[(1LL*x*b)%m] = q;
    }
    int y = x;
    for (int p = 1; p <= n; p++, y = (1LL*y*x)%m) {
        if (auto it = map_.find((1LL*y*k)%m); it != end(map_)) {
            return int(p) * n - it->second + e;
        }
    }
    return -1;
}

