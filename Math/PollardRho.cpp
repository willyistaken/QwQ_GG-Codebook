ll PollardRho(ll x) {// get a factor of x(not prime) in O(x^0.25) 
	if(x%2==0) return 2;
	if(x%3==0) return 3;
    ll s = 0, t = 0;
    ll c = (ll)rand() % (x - 1) + 1;
    int step = 0, g = 1;
    ll val = 1;
    for (g = 1;; g <<= 1, s = t, val = 1) {
        for (step = 1; step <= g; ++step) {
            t =  (__int128(t)*t+c)%x;
            val = __int128(val) * abs(t - s) % x;
            if ((step % 127) == 0) {
                ll d = __gcd(val, x);
                if (d > 1) return d;
            }
        }
        ll d = __gcd(val, x);
        if (d > 1) return d;
    }
}

