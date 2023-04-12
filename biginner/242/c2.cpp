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
	ll mod = 998244353;
	vector<vector<ll> > dp(n);
	rep(i,n)dp[i].resize(9);
	rep(j,9)dp[0][j]=1;
	rep2(1,i,n){
		rep(j,9){
			dp[i][j] = dp[i-1][j];
			if(j-1>=0){
				dp[i][j] += dp[i-1][j-1];
				dp[i][j] %= mod;
			}
			if(j+1<9){
				dp[i][j] += dp[i-1][j+1];
				dp[i][j] %= mod;
			}
		}
	}
	ll ans = 0;
	rep(j,9){
		ans += dp[n-1][j]%mod;
		ans %= mod;
	}
	cout << ans << endl;
}