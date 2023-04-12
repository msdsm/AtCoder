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
	cin >> n >> m;
	vector<ll> x(n);
	cinf(x,n);
	vector<pll> p(m);
	pcin(p,m);
	vector<ll> f(n+1,0);//f[0]はない
	rep(i,m){
		f[p[i].fst] = p[i].snd;
	}

	vector<vector<ll> > dp(n+1);
	rep(i,n+1){
		dp[i].resize(i+1,0);
	}
	//dp[0][0]=0;
	rep(i,n){
		rep(j,dp[i].size()){
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+x[i]+f[j+1]);
			dp[i+1][0] = max(dp[i+1][0], dp[i][j]);
		}
	}

/*
	cout << "debug start dp table" << endl;
	rep(i,n+1){
		rep(j,dp[i].size()){
			cout << dp[i][j] << ' ';
		}cout<<endl;
	}
	cout << "debug end" << endl;
*/
	

	cout << *max_element(dp[n].begin(),dp[n].end()) << endl;
}