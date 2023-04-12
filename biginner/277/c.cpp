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
    vector<int> rank, parents;
    vector<bool> reached;
    UnionFind() {}
    UnionFind(int n) {  // make n trees.
        rank.resize(n, 0);
        parents.resize(n, 0);
        reached.resize(n, false);
        for (int i = 0; i < n; i++) {
            makeTree(i);//最初、iの親はiとする。(iは根)
        }
        reached[0]=true;
    }
    void makeTree(int x) {
        parents[x] = x;  // the parent of x is x
        rank[x] = 0;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    bool isTrue(int x){return reached[x];}
    void unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (rank[x] > rank[y]) {
            parents[y] = x;
            reached[x] = reached[x]||reached[y];
            reached[y] = reached[y]||reached[x];
        } else {
            parents[x] = y;
            reached[y] = reached[y]||reached[x];
            reached[x] = reached[x]||reached[y];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
    int findRoot(int x) {
        if(x != parents[x]){
        	reached[parents[x]] = reached[parents[x]] || reached[x];
        	reached[x] = reached[x] || reached[parents[x]];
        	parents[x] = findRoot(parents[x]);
        }
        return parents[x];
    }
};

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<pll> p(n);
	ll N;
	pcin(p,n);
	set<ll> st;
	st.insert(ll(1));
	rep(i,n){
		st.insert(p[i].fst);
		st.insert(p[i].snd);
	}
	vector<ll> v;//index to value
	map<ll, ll> mp;//value to index
	ll t = 0;
	for(auto itr=st.begin();itr!=st.end();itr++){
		v.push_back(*itr);
		mp[*itr] = t;
		t++;
	}
	N = v.size();
	UnionFind uft = UnionFind(N);
	rep(i,n){
		uft.unite(mp[p[i].fst], mp[p[i].snd]);
	}
	rep(i,n){
		uft.unite(mp[p[i].fst], mp[p[i].snd]);
	}
	rep(i,n){
		uft.unite(mp[p[i].fst], mp[p[i].snd]);
	}
	rep(i,n){
		uft.unite(mp[p[i].fst], mp[p[i].snd]);
	}
	rep(i,n){
		uft.unite(mp[p[i].fst], mp[p[i].snd]);
	}
	rep(i,n){
		uft.unite(mp[p[i].fst], mp[p[i].snd]);
	}

/*
	cout << "debug start v" << endl;
	rep(i,N)cout<<v[i]<<' ';
	cout<<endl;
	cout << "debug end" << endl;

	cout << "debug start" << endl;
	rep(i,N)cout << mp[v[i]] << ' ';
	cout<<endl;
	cout << "debug end" << endl;


	cout << "debug start" << endl;
	rep(i,N)cout<<uft.isTrue(mp[v[i]])<<' ';
	cout<<endl;
	cout << "debug end" << endl;
	
	*/
	
	
	
	rep(i,v.size()){
		if(uft.isTrue(mp[v[v.size()-i-1]])){
			cout << v[v.size()-i-1] << endl;
			return 0;
		}
	}
}