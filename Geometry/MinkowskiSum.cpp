//need Geometry template
void reorder_polygon(vector<P> & pt){
    int pos = 0;
    for(int i = 1; i < size(pt); i++){
        if(pt[i].y < pt[pos].y || (pt[i].y == pt[pos].y && pt[i].x < pt[pos].x))
            pos = i;
    }
    rotate(pt.begin(), pt.begin() + pos, pt.end());
}
vector<P> minkowski(vector<P> A, vector<P> B){
    reorder_polygon(A);
    reorder_polygon(B);
    A.push_back(A[0]);A.push_back(A[1]);
    B.push_back(B[0]);B.push_back(B[1]);
    vector<P> result;
    int i = 0, j = 0;
    while(i < size(A) - 2 || j < size(B) - 2){
        result.push_back(A[i] + B[j]);
        auto cross = (A[i + 1] - A[i])^(B[j + 1] - B[j]);
        if(cross >= 0 && i < size(A) - 2)
            ++i;
        if(cross <= 0 && j < size(B) - 2)
            ++j;
    }
    return result;
}

