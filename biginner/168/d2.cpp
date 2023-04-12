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
	vector<pll> p(m);
	pcin(p,m);
	rep(i,m){
		p[i].fst--;
		p[i].snd--;
	}
	queue<ll> open;
	set<ll> closed;
	vector<bool> v(n);
	vector<ll> ans(n);
	vector<vector<ll> > path(n);
	rep(i,m){
		path[p[i].fst].push_back(p[i].snd);
		path[p[i].snd].push_back(p[i].fst);
	}
	open.push(0);
	while(!open.empty()){
		ll tmp = open.front();
		open.pop();
		closed.insert(tmp);
		rep(i,path[tmp].size()){
			if(!v[path[tmp][i]]){
				open.push(path[tmp][i]);
				v[path[tmp][i]] = true;
				ans[path[tmp][i]] = tmp+1;
			}
		}
	}
	rep(i,n){
		if(!v[i]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	rep2(1,i,n){
		cout << ans[i] << endl;
	}
}