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
	ll n;
	cin >> n;
	vector<ll> a(n),b(n);
	rep(i,n){
		cin >> a[i] >> b[i];
	}
	vector<vector<ll> > dp(n);
	rep(i,n)dp[i].resize(2);
	dp[0][0] = 1;
	dp[0][1] = 1;
	rep2(1,i,n){
		if(a[i]!=a[i-1]){
			dp[i][0] += dp[i-1][0];
			dp[i][0] %= mod;
		}
		if(b[i]!=a[i-1]){
			dp[i][1] += dp[i-1][0];
			dp[i][1] %= mod;
		}
		if(a[i]!=b[i-1]){
			dp[i][0] += dp[i-1][1];
			dp[i][0] %= mod;
		}
		if(b[i]!=b[i-1]){
			dp[i][1] += dp[i-1][1];
			dp[i][1] %= mod;
		}
	}

	ll ans = dp[n-1][0]+dp[n-1][1];
	ans %= mod;
	cout << ans << endl;
}