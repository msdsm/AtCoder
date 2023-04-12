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
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	cinf(a,n);
	vector<vector<ll> > path(n);
	vector<ll> cost1(n);//消す場合
	vector<ll> cost2(n);//残す場合 つかわない
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
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	ll min = numeric_limits<ll>::max();
/*
	ll s=0;
	rep(i,n){
		if(min>cost1[i]){
			min=cost1[i];
			s = i;
		}
	}
	pq.push(pll(cost1[s], s));
*/
	rep(i,n)pq.push(pll(cost1[i], i));
	vector<bool> erased(n, false);
	ll ans = numeric_limits<ll>::min();
	while(!pq.empty()){
		pll tmp = pq.top();
		pq.pop();
		ll node = tmp.snd;
		ll c = tmp.fst;
/*
		cout << "debug start" << endl;
		cout << node << endl;
		cout << c << endl;
		cout << "debug end" << endl;
*/		
		
		if(erased[node])
			continue;
		ans = max(ans,c);
		erased[node] = true;
		rep(i,path[node].size()){
			ll next = path[node][i];
			cost1[next] -= a[node];
		}
		rep(i,path[node].size()){
			ll next = path[node][i];
			if(!erased[next]){
				pq.push(pll(cost1[next],next));
			}
		}
	}
	cout << ans << endl;
}