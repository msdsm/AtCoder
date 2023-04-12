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

ll inf = numeric_limits<ll>::max();

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll m,n;
	cin >> m >> n;
	vector<vector<ll> > dp(n);
	rep(i,n)dp[i].resize(n+1,inf);
	vector<ll> a(n),c(n),x(m);
	cinf(a,n);
	cinf(c,n);
	cinf(x,m);
	rep(i,m)x[i]--;
	set<ll> st;
	rep(i,m)st.insert(x[i]);

	if(st.count(n-1)>0){
		dp[n-1][1] = a[n-1]+c[n-1];
		dp[n-1][0] = inf;
	}else{
		dp[n-1][0] = 0;
		dp[n-1][1] = a[n-1]+c[n-1];
	}
	for(ll i = n-2; i>=0; i--){
		rep(j,n+1){
			if(st.count(i)>0){
				dp[i][j]
			}else{
				dp[i][j] = min(dp[i][j],dp[i+1][j]);//買わない
				dp[i][j]
			}
		}
	}
	ll ans = inf;
	rep(j,n+1){
		if(ans>dp[0][j])
			ans = dp[0][j];
	}
	cout << ans << endl;
}