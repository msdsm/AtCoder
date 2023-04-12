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

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

ll mod = 998244353;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m,k;
	cin >> n >> m >> k;
	ll minv = modinv(m,mod);
	vector<vector<ll> > dp(k+1);
	rep(i,k+1)dp[i].resize(n+1);
	dp[0][0] = 1;
	rep(i,k){
		rep(j,n+1){
			if(dp[i][j]==0)continue;
			if(j==n){//すでにゴール
				dp[i+1][j] += dp[i][j];//サイコロ何でても同じ
				dp[i+1][j] %= mod;
				continue;
			}
			rep(t,m){
				ll next = j+t+1;
				if(next>n)
					next = 2*n-j-t-1;
				dp[i+1][next] += (dp[i][j]*minv)%mod;
				dp[i+1][next] %= mod;
			}
		}
	}
	cout << dp[k][n]%mod << endl;
}