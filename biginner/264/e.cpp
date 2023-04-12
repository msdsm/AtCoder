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
	vector<bool> bl;
	UnionFind() {}
    UnionFind(ll n, ll m) {  // make n trees.
    	rank.resize(n+m, 0);
    	parents.resize(n+m, 0);
    	cnt.resize(n+m,1);
    	bl.resize(n+m,false);
    	for (ll i = 0; i < n+m; i++) {
            //makeTree(i);//最初、iの親はiとする。(iは根)
    		parents[i]=i;
    		rank[i]=0;
    		if(i<n){
    			cnt[i]=1;
    			bl[i]=false;
    		}else{
    			cnt[i]=0;
    			bl[i]=true;
    		}
    	}
    }
    /*
    void makeTree(ll x) {
        parents[x] = x;  // the parent of x is x
        rank[x] = 0;
        cnt[x]=1;
    }
    */
    bool isSame(ll x, ll y) { return findRoot(x) == findRoot(y); }
    void unite(ll x, ll y) {
    	x = findRoot(x);
    	y = findRoot(y);
    	if (rank[x] > rank[y]) {
    		parents[y] = x;
    		cnt[x]+=cnt[y];
    		bl[x] = bl[x] || bl[y];
    	} else {
    		parents[x] = y;
    		cnt[y]+=cnt[x];
    		bl[y] = bl[y] || bl[x];
    		if (rank[x] == rank[y]) {
    			rank[y]++;
    		}
    	}
    }
    ll findRoot(int x) {
    	if(x != parents[x]){
    		cnt[parents[x]]=max(cnt[x],cnt[parents[x]]);
    		bl[parents[x]] = bl[x] || bl[parents[x]];
    		parents[x] = findRoot(parents[x]);
    	}
    	return parents[x];
    }
    ll size(ll x){
    	return cnt[findRoot(x)];
    }
    bool electricity(ll x){
    	return bl[findRoot(x)];
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
	ll n,m,e;
	cin >> n >> m >> e;

	vector<pll> edge(e);
	rep(i,e){
		ll u,v;
		cin >> u >> v;
		u--;
		v--;
		edge[i] = pll(u,v);
	}

	ll q;
	cin >> q;

	vector<ll> idx(q);
	rep(i,q){
		ll x;
		cin >> x;
		x--;
		idx[i]=x;
	}

	set<ll> st;
	rep(i,q)st.insert(idx[i]);

	UnionFind uft = UnionFind(n, m);

	rep(i,e){
		if(st.count(i)==0){
			ll u = edge[i].fst;
			ll v = edge[i].snd;
			uft.unite(u,v);
		}
	}

	vector<ll> ans(q);

	set<ll> pre;

	rep(i,n+m){
		pre.insert(uft.findRoot(i));
	}

	for(auto itr=pre.begin();itr!=pre.end();itr++){
		if(uft.electricity(*itr)){
			ans[q-1] += uft.size(*itr);
		}
	}

	for(ll i = q-2; i >= ll(0); i--){
		ll u = edge[idx[i+1]].fst;
		ll v = edge[idx[i+1]].snd;
		ans[i] = ans[i+1];

		if(uft.isSame(u,v))
			continue;
		

		ll p1 = uft.findRoot(u);
		ll p2 = uft.findRoot(v);

		if((!uft.electricity(p1)) && uft.electricity(p2)){
			ans[i] += uft.size(p1);
		}

		if(uft.electricity(p1) && !uft.electricity(p2)){
			ans[i] += uft.size(p2);
		}

		uft.unite(u,v);
		
		/*
		if(uft.findRoot(u)==p1){
			pre.erase(p2);
		}else{
			pre.erase(p1);
		}
		*/
	}
	
	rep(i,q){
		cout << ans[i] << endl;
	}
}