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
	ll inf = numeric_limits<ll>::min();
	cin >> n >> m;
	vector<ll> a(n);
	cinf(a,n);
	vector<vector<ll> > dp(n);
	rep(i,n)dp[i].resize(min(m+1,i+2), inf);
	dp[0][0]=0;
	dp[0][1]=a[0];
	rep(i,n-1){
		rep(j,dp[i].size()){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if(j+1<dp[i+1].size())
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(j+1)*a[i+1]);
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,n){
		rep(j,dp[i].size()){
			cout << dp[i][j] << ' ';
		}cout<<endl;
	}
	cout << "debug end" << endl;
*/
	
	cout << dp[n-1][m] << endl;
}