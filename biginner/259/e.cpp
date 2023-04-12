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
	ll n;
	cin >> n;
	vector<vector<ll> > p,e;
	vector<ll> m(n);
	p.resize(n);
	e.resize(n);
	rep(i,n){
		cin >> m[i];
		rep(j,m[i]){
			ll pp,ee;
			cin >> pp >> ee;
			p[i].push_back(pp);
			e[i].push_back(ee);
		}
	}
	map<ll, priority_queue<ll,vector<ll>, less<ll> > > mp;
	rep(i,n){
		rep(j,m[i]){
			mp[p[i][j]].push(e[i][j]);
		}
	}

	ll ans = 0;
	ll inv = 0;
	rep(i,n){
		rep(j,m[i]){
			if(mp[p[i][j]].top()==e[i][j]){
				ll tmp = mp[p[i][j]].top();
				mp[p[i][j]].pop();
				if(mp[p[i][j]].empty() || mp[p[i][j]].top()!=e[i][j]){
					ans++;
					mp[p[i][j]].push(tmp);
					break;
				}else{
					mp[p[i][j]].push(tmp);
				}
			}
			if(j==m[i]-1){//かわらず
				inv++;
			}
		}
	}
	if(inv>0)
		ans++;
	cout << ans << endl;
}