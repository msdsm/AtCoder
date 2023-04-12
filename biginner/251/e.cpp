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
	vector<ll> a(n);
	ll inf =  numeric_limits<ll>::max();
	cinf(a,n);
	vector<vector<ll> > dp(n);
	rep(i,n)dp[i].resize(2,inf);
	dp[0][0]=0;dp[0][1]=inf;
	rep2(1,i,n){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = min(dp[i-1][1],dp[i-1][0])+a[i];
	}
	ll ans = dp[n-1][1];


	rep(i,n)rep(j,2)dp[i][j]=inf;
	dp[0][0]=inf;dp[0][1]=a[0];
	rep2(1,i,n){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = min(dp[i-1][1],dp[i-1][0])+a[i];
	}
	if(ans>min(dp[n-1][0],dp[n-1][1]))
		ans = min(dp[n-1][0],dp[n-1][1]);
	cout << ans << endl;
}