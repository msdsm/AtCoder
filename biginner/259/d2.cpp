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

using P = pair<pll, ll>;

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

bool f(P p1, P p2){//繋がっているかどうか
	ll d2 = (p1.fst.fst-p2.fst.fst)*(p1.fst.fst-p2.fst.fst)+(p1.fst.snd-p2.fst.snd)*(p1.fst.snd-p2.fst.snd);
	ll r2 = p2.snd;
	ll r1 = p1.snd;
	if((r1-r2)*(r1-r2)<=d2 && d2<=(r1+r2)*(r1+r2))
		return true;
	else
		return false;
}

bool ff(P p,ll x, ll y){
	if((x-p.fst.fst)*(x-p.fst.fst)+(y-p.fst.snd)*(y-p.fst.snd)==p.snd*p.snd)
		return true;
	else
		return false;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	UnionFind uft = UnionFind(n);
	pll s,t;
	cin >> s.fst >> s.snd >> t.fst >> t.snd;
	vector<P> p(n);
	vector<ll> indices;
	rep(i,n){
		cin >> p[i].fst.fst >> p[i].fst.snd >> p[i].snd;
	}
	rep(i,n){
		rep2(i+1,j,n){
			if(f(p[i],p[j]))
				uft.unite(i,j);
		}
	}
	ll idxs,idxt;
	rep(i,n){
		if(ff(p[i],s.fst,s.snd))
			idxs = i;
		if(ff(p[i],t.fst,t.snd))
			idxt = i;
	}
	if(uft.isSame(idxs,idxt))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	//cout << f(p[0],p[1]) << endl;
	//cout << f(p[1],p[2]) << endl;
}