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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll inf = numeric_limits<ll>::max();

	ll n,m;
	cin >> n >> m;
	vector<vector<pll> > e(n);
	rep(i,m){
		ll a,b,t;
		cin >> a >> b >> t;
		a--;
		b--;
		e[a].push_back(pll(t,b));
		e[b].push_back(pll(t,a));
	}
	ll ans = inf;
	rep(i,n){
		priority_queue<pll,vector<pll>,greater<pll> > open;
		open.push(pll(0,i));
		ll num = 0;
		vector<ll> cost(n,inf);
		cost[i]=0;
		while(!open.empty()){
			pll tmp = open.top();
			open.pop();//取り出した時に確定
			ll v = tmp.snd;
			ll c = tmp.fst;
			if(cost[v]<c)
				continue;
			cost[v]=c;
			rep(j,e[v].size()){
				if(cost[e[v][j].snd]>cost[v]+e[v][j].fst)
					open.push(pll(cost[v]+e[v][j].fst , e[v][j].snd));
			}
		}
		rep(i,n){
			num = max(num,cost[i]);
		}
		ans = min(ans,num);
	}
	cout << ans << endl;
}