/* UnionFind：素集合系管理の構造体(union by rank)
    isSame(x, y): x と y が同じ集合にいるか。 計算量はならし O(α(n))
    unite(x, y): x と y を同じ集合にする。計算量はならし O(α(n))
*/
struct UnionFind {  // The range of node number is u 0 v n-1
    vector<int> rank, parents;
    UnionFind() {}
    UnionFind(int n) {  // make n trees.
        rank.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) {
            makeTree(i);//最初、iの親はiとする。(iは根)
        }
    }
    void makeTree(int x) {
        parents[x] = x;  // the parent of x is x
        rank[x] = 0;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    void unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (rank[x] > rank[y]) {
            parents[y] = x;
        } else {
            parents[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
    int findRoot(int x) {
        if (x != parents[x]) parents[x] = findRoot(parents[x]);
        return parents[x];
    }
};





/*-------------------------------------------------------------------------*/
/*
自作UnionFind
各要素にたいしてその要素が含まれるグループの元の個数をsize(x)で得る
グループの元の個数を代表としてグループの値のcntに格納している
*/
struct UnionFind {  // The range of node number is u 0 v n-1
    vector<ll> rank, parents,cnt;
    UnionFind() {}
    UnionFind(ll n) {  // make n trees.
        rank.resize(n, 0);
        parents.resize(n, 0);
        cnt.resize(n,1);
        for (ll i = 0; i < n; i++) {
            makeTree(i);//最初、iの親はiとする。(iは根)
        }
    }
    void makeTree(ll x) {
        parents[x] = x;  // the parent of x is x
        rank[x] = 0;
        cnt[x]=1;
    }
    bool isSame(ll x, ll y) { return findRoot(x) == findRoot(y); }
    void unite(ll x, ll y) {
        x = findRoot(x);
        y = findRoot(y);
        if (rank[x] > rank[y]) {
            parents[y] = x;
            cnt[x]+=cnt[y];
        } else {
            parents[x] = y;
            cnt[y]+=cnt[x];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
    ll findRoot(int x) {
        if(x != parents[x]){
            cnt[parents[x]]=max(cnt[x],cnt[parents[x]]);
            parents[x] = findRoot(parents[x]);
        }
        return parents[x];
    }
    ll size(ll x){
        return cnt[findRoot(x)];
    }
    void debug(){
        cout << "debug start" << endl;
        rep(i,cnt.size()){
            cout << i << ':' << endl;
            cout << findRoot(i) << endl;
            cout << cnt[i] << endl;
        }
        cout << "debug end" << endl;
    }
};


