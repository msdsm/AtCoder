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
	ll n,m,k;
	cin >> n >> m >> k;
	vector<vector<ll> > dp(n+1);
	rep(i,n+1)dp[i].resize(k+1);
	rep2(1,j,m+1){
		dp[1][j]=1;
	}
	rep2(1,i,n){
		rep2(1,j,k+1){
			rep2(j+1,jj,min(k+1,j+m+1)){
				dp[i+1][jj] += dp[i][j];
				dp[i+1][jj] %= mod;
			}
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,n){
		rep(j,k+1){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/	
	
	ll ans = 0;
	rep2(1,j,k+1){
		ans += dp[n][j]%mod;
		ans %= mod;
	}
	cout << ans%mod << endl;
}