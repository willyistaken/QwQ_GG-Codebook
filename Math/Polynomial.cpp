
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
	Poly pow(T k){
		Poly d = (*this).ln();
		d = d*k;
		d = d.exp();
		return d;
	}
};
template<typename T>
NTT Poly<T>::con;
