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

ll ans;
vector<ll> visited(200010);
vector<vector<ll> > path(200010);
ll limit = 1000000;
void dfs(ll now){
	if(ans>limit)
		return;
/*
	cout << "debug start" << endl;
	cout << now << endl;
	cout << "debug end" << endl;
*/	
	
	visited[now]=true;
	ans++;
	rep(i,path[now].size()){
		ll next = path[now][i];
		if(!visited[next]){
			dfs(next);
		}
	}
	visited[now]=false;
	return;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<pll> p(m);
	pcin(p,m);
	rep(i,m){
		p[i].fst--;
		p[i].snd--;
		path[p[i].fst].push_back(p[i].snd);
		path[p[i].snd].push_back(p[i].fst);
	}
	dfs(0);
	cout << min(limit,ans) << endl;
}