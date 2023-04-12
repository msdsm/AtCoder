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

ll x;
ll g;

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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<pair<ll, char> > l(m),r(m);
	rep(i,m)cin>>l[i].fst>>l[i].snd>>r[i].fst>>r[i].snd;
	rep(i,m){
		l[i].fst--;
		r[i].fst--;
	}
	UnionFind uft = UnionFind(2*n);
	rep(i,n){
		uft.unite(i,i+n);
	}
	rep(i,m){
		ll a = l[i].fst;
		ll b = r[i].fst;
		if(l[i].snd=='B')
			a+=n;
		if(r[i].snd=='B')
			b+=n;
		if(uft.isSame(a,b)){
			x++;
			uft.unite(a,b);
		}else{
			uft.unite(a,b);
		}
	}
	set<ll> st;
	rep(i,n){
		ll tmp = uft.findRoot(i);
		if(tmp>=n)tmp-=n;
		st.insert(tmp);
	}
/*
	cout << "debug start" << endl;
	for(auto itr=st.begin();itr!=st.end();itr++){
		cout << *itr << endl;
	}
	cout << "debug end" << endl;
*/	
	
	cout << x << ' ' << st.size()-x << endl;
}