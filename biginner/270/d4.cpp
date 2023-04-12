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
	ll n,k;
	cin >> n >> k;
	vector<ll> a(k);
	cinf(a,k);
	vector<vector<ll> > dp(n+1);
	rep(i,n+1)dp[i].resize(2);
	rep(i,n+1){
		dp[i][0]=0;
		dp[i][1]=0;
	}
	dp[0][0]=0;
	dp[1][0]=0;
	rep(i,n+1){
		rep(j,2){
			rep(idx,k){
				if(i+a[idx]<=n){
					dp[i+a[idx]][0] = max(dp[i+a[idx]][0], dp[i][1]+a[idx]);
					dp[i+a[idx]][1] = i+a[idx]-dp[i+a[idx]][0];
					/*
					if(j==0)
						dp[i+a[idx]][j] = max(dp[i+a[idx]][j], dp[i][1-j]+a[idx]);
					else
						dp[i+a[idx]][j] = min(dp[i+a[idx]][j], dp[i][1-j]);
						*/
				}
			}
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,n+1){
		rep(j,2){
			cout << dp[i][j] << ' ';
		}cout<<endl;
	}
	cout << "debug end" << endl;
*/	
	
	cout << dp[n][0] << endl;
	//cout << dp[n][1] << endl;
}