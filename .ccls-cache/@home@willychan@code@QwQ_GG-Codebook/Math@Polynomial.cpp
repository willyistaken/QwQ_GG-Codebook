template<typename T>
struct Poly:vector<T>{
	using vector<T>::vector;
	static NTT  con;
	Poly(const Poly &p,int m): vector<T>(m){
		copy_n(p.data(),min(size(p),m),this->data());
	}
	Poly& isz(int m) { return this->resize(m), *this; }	
	Poly operator+(T const &b){
		Poly ret = Poly(*this,size(*this));
		ret[0]+=b;
		return ret;
	}
	Poly operator*(T const &b){
		Poly ret = Poly(*this,size(*this));
		for(int i=0;i<size(ret);i++) ret[i]*=b;
		return ret;
	}
	Poly operator+(Poly &b){
		Poly ret = Poly(*this,max(size(b),size(*this)));
		for(int i=0;i<size(ret);i++) ret[i]+=b[i];
		return ret;
	}
	Poly operator*(Poly b){
		return con.pmul(*this,b);
	}
	Poly dx() {
		Poly ret(size(*this)-1);
		for(int i=0;i<size(ret);i++) ret[i]=T(i+1)*(*this)[i+1];
		ret.resize(max(1,size(ret)));
		return ret;
	}
	Poly ix() {
		Poly ret(size(*this) + 1);
		for(int i=1;i<size(ret);i++) ret[i] = T(1)/T(i) * (*this)[i-1];
		return ret;
	}
	Poly inv() {
		int n = size(*this);
		if(n==1) return {T(1)/(*this)[0]};
		int m = n<<1;
		while(m^lowbit(m)) m+=lowbit(m);
		Poly xi = Poly(*this,(n+1)/2).inv().isz(m);
		Poly yi(*this,m);
		con.dft(xi);con.dft(yi);
		for(int i=0;i<m;i++){
			xi[i] = xi[i]*(mi(2)-yi[i]*xi[i]);
		}
		con.idft(xi);
		return xi.isz(n);
	}
	Poly ln(){
		int n = size(*this);
		Poly ret = (*this).dx();
		Poly inv = (*this).inv();
		ret = ret*inv;
		ret.resize(n);
		return ret.ix().isz(n);
	}
	Poly exp(){
		int n = size(*this);
		if(n==1) return {T(1)};
		Poly xi = Poly(*this,(n+1)/2).exp().isz(n);
		Poly yi = xi.ln();yi[0]=T(-1);
		for(int i=0;i<n;i++) yi[i] = (*this)[i]-yi[i];
		return (xi*yi).isz(n);	
	}
	Poly pow(ll k){
		int n = size(*this);
		int nz = 0;
		while (nz < n && (*this)[nz].v == 0) nz++;
		if (nz > 0 && k > 0 && (double)nz * k >= n) return Poly(n);
		int offset = nz * k;
		if (!k)  return Poly(Poly{1}, n);
		mi c = (*this)[nz];
		ll p_minus_1 = M - 1; 
		mi c_k = c.pow(k % p_minus_1);
		mi inv_c = mi(1)/c;
		int m = n - offset;
		if (m <= 0) return Poly(n);
		Poly Q(m);
		for (int i = 0; i < m; i++) {
			if (nz + i < n) {
				Q[i] = (*this)[nz + i] * inv_c;
			}
		}
		Poly d = Q.ln();
		d = d * mi(k % M); 
		d = d.exp();
		for(int i = 0; i < m; i++)  d[i] = d[i] * c_k;
		Poly Res(n);
		for (int i = 0; i < m; i++)  Res[offset + i] = d[i];
		return Res;
	}
};
template<typename T>
NTT Poly<T>::con;
