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


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<pll> p(m);
	rep(i,m){
		ll a,b;
		cin >> a >> b;
		a--;b--;
		p[i].fst=a;
		p[i].snd=b;
	}

	UnionFind uft = UnionFind(n);
	rep(i,m){
		if(!uft.isSame(p[i].fst,p[i].snd))
			uft.unite(p[i].fst,p[i].snd);
	}
	ll max = 0;
	rep(i,n){
		if(max<uft.size(i))
			max=uft.size(i);
	}
	cout << max << endl;
	//uft.debug();
}