struct TotalBS {
    int Q;
    vector<int> ans;
    TotalBS(int _Q) {
        Q=_Q;
        ans.resize(Q);
    }
    void split(vector<int> &qrys,vecotr<int> &ok,vector<int> &fail) {
        for(auto i :qrys) {
        }
        vector<int>.swap(qrys);
        return;
    }
    void do_things(int l,int mid) {
        return;
    }
    void undo_things(int l,int mid) {
        return;
    }
    void total_BS(int l, int r, vector<int> &qrys) {
        if (l == r) {
            for(auto i : qrys) {
                ans[i] = l;
            }
        }
        int mid = (l + r) / 2;
        do_things(l, mid);
        vector<int> lft,rgt;
        split(qrys,lft,rgt);
        total_BS(mid + 1, r, rgt);
        undo_things(l, mid);
        total_BS(l, mid, lft);
    }
};
