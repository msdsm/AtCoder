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

ll ans = 0;
ll n,m;
vector<vector<ll> > path;
vector<bool> visited;

void f(ll src){
	visited[src] = true;
	rep(i,path[src].size()){
		ll next = path[src][i];
		if(!visited[next]){
			ans++;
			if(ans==1000000){
				return;
			}
			f(next);
		}
	}
	return;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	cin >> n >> m;
	path.resize(n);
	visited.resize(n,false);
	rep(i,m){
		ll u,v;
		cin >> u >> v;
		u--;
		v--;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	ans++;
	f(0);
	cout << ans << endl;
}