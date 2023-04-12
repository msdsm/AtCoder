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
	vector<vector<ll> > er(n);
	vector<ll> d(n,0);
	rep(i,m){
		ll u,v;
		cin >> u >> v;
		er[v-1].push_back(u-1);
		d[u-1]++;
	}
	queue<ll> q;
	rep(i,n){
		if(d[i]==0)
			q.push(i);
	}
	ll ans = n;
	while(!q.empty()){
		ans--;
		ll tmp = q.front();
		q.pop();
		rep(i,er[tmp].size()){
			ll node = er[tmp][i];
			d[node]--;
			if(d[node]==0){
				q.push(node);
			}
		}
	}
	cout << ans << endl;
}