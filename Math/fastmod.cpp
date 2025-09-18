inline int ad(int a,int b){
	a+=b;
	return a>=M?a-M:a;
}
inline int ml(ll a, ll b) {
    int res= a * b - (uint64_t)((__uint128_t(-1ULL / M) * a * b) >> 64) * M;
	return res>=M?res-M:res;
}

