struct edge{
	int u,v,w;
};
vector<edge> result;
vector<edge> ed;
void GomoryHu(int N){
	vector<int> par(N,0);
	for(int i=1;i<N;i++){ 
		FLOW din;
		for(const auto &[u,v,c]:ed){
			din.addedge(u,v,c,c);
		}
		din.s = i;
		din.t = par[i];
		result.push_back({i,par[i],din.getflow()});
		for(int j=i+1;j<N;++j){
			if(par[j]==par[i] && din.dp[j]<INF) par[j]=i;
		}
	}
}
