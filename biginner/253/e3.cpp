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
	vector<vector<ll> > dp(n);
	rep(i,n)dp[i].resize(m,0);
	dp[0][0]=1;
	rep2(1,j,m){
		dp[0][j] = dp[0][j-1]+1;
		dp[0][j] %= mod;
	}
	rep2(1,i,n){
		rep(j,m){

			cout << "debug start i,j" << endl;
			cout << i << ' ' << j << endl;
			cout << "debug end" << endl;
			
			
			if(j!=0)
				dp[i][j] += dp[i][j-1]%mod;
			dp[i][j]%=mod;
			if((j-k)>=0)
				dp[i][j] += dp[i-1][j-k]%mod;
			dp[i][j]%=mod;

cout << "debug start dp0" << endl;
cout << dp[i][j] << endl;
cout << "debug end" << endl;


			if((j+k)<m && j+k-1>=0)
				dp[i][j] += (dp[i-1][m-1]%mod-dp[i-1][j+k-1]%mod+mod)%mod;
			if((j+k)<m && j+k-1<0)
				dp[i][j] += dp[i-1][m-1]%mod;
			dp[i][j]%=mod;


cout << "debug start dp1" << endl;
cout << dp[i][j] << endl;
cout << "debug end" << endl;


			if(k==0){
				dp[i][j] += mod;
				if(j>0)
					dp[i][j] -= (dp[i-1][j]%mod-dp[i-1][j-1]%mod+mod)%mod;
				else
					dp[i][j] -= dp[i][j]%mod;
				dp[i][j]%=mod;
			}

cout << "debug start dp2" << endl;
cout << dp[i][j] << endl;
cout << "debug end" << endl;


		}
	}

	cout << "debug start dp" << endl;
	rep(i,n){
		rep(j,m){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;

	
	cout << dp[n-1][m-1]%mod << endl;
}