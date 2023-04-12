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

bool f(pll p1, pll p2){
	ll i = p1.fst;
	ll j = p1.snd;
	ll x = p2.fst;
	ll y = p2.snd;
	if(x==i-1&&y==j-1)
		return true;
	else if(x==i-1&&y==j)
		return true;
	else if(x==i&&y==j-1)
		return true;
	else if(x==i&&y==j+1)
		return true;
	else if(x==i+1&&y==j)
		return true;
	else if(x==i+1&&y==j+1)
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
	vector<pll> p(n);
	rep(i,n){
		cin >> p[i].fst >> p[i].snd;
	}
	UnionFind uft = UnionFind(n);
	rep(i,n){
		rep2(i+1,j,n){
			if(f(p[i], p[j]))
				uft.unite(i, j);
		}
	}
	vector<ll> v;
	ll cnt = 0;
	rep(i,n){
		bool flag = false;
		rep(j,v.size()){
			if(uft.isSame(i, v[j]))
				flag = true;
		}
		if(flag)
			continue;
		v.push_back(i);
		cnt++;
	}
	cout << cnt << endl;
}