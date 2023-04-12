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

ll mod = 998244353;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m,k,s,t,x;
	cin >> n >> m >> k >> s >> t >> x;
	s--;
	t--;
	x--;
	vector<pll> p(m);
	vector<vector<ll> > path(n);
	rep(i,m){
		ll u,v;
		cin >> u >> v;
		u--;
		v--;
		p[i].fst=u;
		p[i].snd=v;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	vector<vector<vector<ll> > > dp(k+1);
	rep(i,k+1)dp[i].resize(n);
	rep(i,k+1){
		rep(j,n){
			dp[i][j].resize(2,0);
		}
	}
	dp[0][s][0] = 1;
	rep(i,k){
		rep(j,n){
			if(dp[i][j][0]>0){
				for(auto itr=path[j].begin();itr!=path[j].end();itr++){
					if((*itr)!=x){
						dp[i+1][*itr][0] += dp[i][j][0];
						dp[i+1][*itr][0] %= mod;
					}
					else{
						dp[i+1][*itr][1] += dp[i][j][0];
						dp[i+1][*itr][1] %= mod;
					}
				}
			}
			if(dp[i][j][1]>0){
				for(auto itr=path[j].begin();itr!=path[j].end();itr++){
					if((*itr)==x){
						dp[i+1][*itr][0] += dp[i][j][1];
						dp[i+1][*itr][0] %= mod;
					}
					else{
						dp[i+1][*itr][1] += dp[i][j][1];
						dp[i+1][*itr][1] %= mod;
					}
				}
			}
		}
	}
	cout << dp[k][t][0] << endl;
}