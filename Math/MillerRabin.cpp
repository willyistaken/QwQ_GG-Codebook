bool isPrime(const uint64_t n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	uint64_t A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), D = n >> s;
	for (auto a : A) {
		uint64_t p =1,g=a%n,i=s,d=D;
		for(;d;g=__int128(g)*g%n,d/=2) if(d&1) p = __int128(p)*g%n;
		while (p != 1 && p != n - 1 && a % n && i--) p = __int128(p)*p%n;
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
