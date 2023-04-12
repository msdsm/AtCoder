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

using P = pair<ll, pair<ll,bool> >  //(cost, (node,どっちか))

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<vector<ll> > path(n);
	vector<ll> cost1(n);//消す場合
	vector<ll> cost2(n);//残す場合
	rep(i,m){
		ll u,v;
		cin >> u >> v;
		u--;
		v--;
		path[u].push_back(v);
		path[v].push_back(u);
		cost1[u] += a[v];
		cost1[v] += a[u];
	}
	rep(i,n){
		cost2[i] = a[i]*path[i].size();
	}
	priority_queue<P,vector<P>, greater<P> > pq;
}