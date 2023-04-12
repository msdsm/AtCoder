//ABC235 E問題

//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
#define fst first
#define snd second
#define pcin(x,n) for(ll i=0;i<(n);i++)cin>>x[i].fst>>x[i].snd;
#define pdebug(x) cout << '(' << x.fst << ',' << x.snd << ")\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;


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

//辺の定義
//Edge e = {u,v,cost}で初期化宣言可能
struct Edge {
    long long u;
    long long v;
    long long cost;
};

/*辺を直接比較するための関数*/
/*sort(Edge e.begin(),e.end(),comp_e)で重みでソート可能*/
bool comp_e(const Edge &e1, const Edge &e2){return e1.cost < e2.cost;}

bool compare_original(pair<Edge,ll> e1, pair<Edge,ll> e2){
	return comp_e(e1.fst,e2.fst);
}



/* Kruskal :クラスカル法で minimum spanning tree を求める構造体
    入力: 辺のvector, 頂点数V
    最小全域木の重みの総和: sum
    計算量: O(|E|log|V|)
*/
struct Kruskal {
    UnionFind uft;
    long long sum;  // 最小全域木の重みの総和
    vector<Edge> edges;
    int V;
    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }
    void init() {
        sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
        uft = UnionFind(V);
        sum = 0;
        for (auto e : edges) {
            if (!uft.isSame(e.u, e.v)) { // 閉路にならなければ加える
                uft.unite(e.u, e.v);
                sum += e.cost;
            }
        }
    }
};


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m,q;
	cin >> n >> m >> q;
	vector<bool> ans(q);
	vector<pair<Edge,ll> >edge(m+q);
	rep(i,m){
		ll a,b,c;
		cin >> a >> b >> c;
		Edge e = {--a,--b,c};
		edge[i] = pair<Edge,ll>(e,-1);
	}
	rep(i,q){
		ll a,b,c;
		cin >> a >> b >> c;
		Edge e = {--a,--b,c};
		edge[i+m] = pair<Edge,ll>(e,i);
	}
	sort(edge.begin(),edge.end(),compare_original);
/*
	cout << "debug start" << endl;
	rep(i,m+q){
		cout << edge[i].fst.u << ' ' << edge[i].fst.v << ' ' << edge[i].fst.cost << ' ' << edge[i].snd << endl;
	}
	cout << "debug end" << endl;
*/
	UnionFind uft = UnionFind(n);
	for(auto p : edge){
		Edge e = p.fst;
		if(p.snd==-1){
			if(!uft.isSame(e.u,e.v))
				uft.unite(e.u,e.v);
		}else{
			if(!uft.isSame(e.u,e.v))
				ans[p.snd]=true;
			else
				ans[p.snd]=false;
		}
	}
	rep(i,q){
		if(ans[i])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}	
}