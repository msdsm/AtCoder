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
	rep(i,n)dp[i].resize(m);
	dp[0][0]=1;
	rep2(1,j,m){
		dp[0][j] = dp[0][j-1]+1;
	}
	rep2(1,i,n){
		rep(j,m){
			if(j!=0)
				dp[i][j] += dp[i][j-1];
			if((j-k)>=0)
				dp[i][j] += dp[i-1][j-k];
			if((j+k)<m)
				dp[i][j] += dp[i-1][m-1] - dp[i-1][j+k-1];
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
	
	
	cout << dp[n-1][m-1] << endl;
}