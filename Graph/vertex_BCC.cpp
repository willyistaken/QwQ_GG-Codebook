struct BCC
{
	int n, dft, nbcc;
	vector<pii> Edges;
	vector<int> low, dfn, bln, stk, is_ap, bln_, BCCofE, bct_vst;
	vector<vector<pii>> G;
	vector<vector<int>> bcc, nG;
	void make_bcc(int u)
	{
		bcc.emplace_back(1, u);
		for (; stk.back() != u; stk.pop_back())
			bln[stk.back()] = nbcc, bcc[nbcc].emplace_back(stk.back());
		stk.pop_back(), bln[u] = nbcc++;
	}
	void dfs(int u, int f)
	{
		int child = 0;
		low[u] = dfn[u] = ++dft, stk.emplace_back(u);
		for (auto [v, id] : G[u])
			if (!dfn[v])
			{
				dfs(v, u), ++child;
				low[u] = min(low[u], low[v]);
				if (dfn[u] <= low[v])
				{
					is_ap[u] = 1, bln[u] = nbcc;
					make_bcc(v), bcc.back().emplace_back(u);
				}
			}
			else if (dfn[v] < dfn[u] && v != f)
				low[u] = min(low[u], dfn[v]);
		if (f == -1 && child < 2)
			is_ap[u] = 0;
		if (f == -1 && child == 0)
			make_bcc(u);
	}
	BCC(int _n) : n(_n), dft(0), nbcc(0), low(n), dfn(n), bln(n), is_ap(n), G(n) {}
	void solve()
	{
		for (int i = 0; i < size(Edges); ++i)
		{
			G[Edges[i].first].emplace_back(Edges[i].second, i);
			G[Edges[i].second].emplace_back(Edges[i].first, i);
		}
		for (int i = 0; i < n; ++i)
			if (!dfn[i])
				dfs(i, -1);
	}
	void block_cut_tree()
	{
		int tmp = nbcc;
		for (int i = 0; i < n; ++i)
			if (is_ap[i])
				bln[i] = tmp++;
		bln_.resize(tmp);
		for (int i = 0; i < n; ++i)
			bln_[bln[i]] = i;
		nG.assign(tmp, vector<int>(0));
		for (int i = 0; i < nbcc; ++i)
			for (int j : bcc[i])
				if (is_ap[j])
					nG[i].emplace_back(bln[j]), nG[bln[j]].emplace_back(i);
	} // up to 2 * n - 2 nodes!! bln[i] for id
	void dfs_bct(int cur, int fa)
	{
		if (cur < nbcc)
			bct_vst[cur] = 1;
		for (auto i : nG[cur])
		{
			if (i == fa)
				continue;
			if (cur < nbcc)
			{
				for (auto [j, id] : G[bln_[i]])
				{
					auto it = lower_bound(iter(bcc[cur]), j);
					if (it != bcc[cur].end() && *it == j)
						BCCofE[id] = cur;
				}
			}
			else
			{
				for (int j : bcc[i])
				{
					auto it = lower_bound(iter(G[bln_[cur]]), make_pair(j, 0));
					if (it != G[bln_[cur]].end() && it->first == j)
						BCCofE[it->second] = i;
				}
			}
			dfs_bct(i, cur);
		}
	}
	void find_BCCofE()
	{
		for (auto &i : G)
			sort(iter(i));
		for (auto &i : bcc)
			sort(iter(i));
		BCCofE.assign(size(Edges), -1), bct_vst.assign(nbcc, 0);
		for (int i = 0; i < nbcc; ++i)
			if (!bct_vst[i])
				dfs_bct(i, i);
		for (int i = 0; i < size(Edges); ++i)
			if (is_ap[Edges[i].first] || is_ap[Edges[i].second])
				assert(BCCofE[i] != -1);
			else
			{
				assert(BCCofE[i] == -1);
				BCCofE[i] = bln[Edges[i].first];
			}
	}
};
