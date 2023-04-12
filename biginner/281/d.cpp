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
	ll n,k,d;
	cin >> n >> k >> d;
	vector<ll> a(n);
	cinf(a,n);
	vector<vector<vector<ll> > > dp(n+1);
	rep(i,n+1)dp[i].resize(k+1);
	rep(i,n+1){
		rep(j,k+1){
			rep(z,d){
				dp[i][j].resize(d,-1);
			}
		}
	}
	dp[1][0][0]=0;
	dp[1][1][a[0]%d]=a[0];
	rep2(1,i,n){
		rep(j,k+1){
			rep(z,d){
				if(dp[i][j][z]==-1)
					continue;
				dp[i+1][j][z] = max(dp[i+1][j][z], dp[i][j][z]);
				if(j==k)continue;
				dp[i+1][j+1][(z+a[i])%d] = max(dp[i+1][j+1][(z+a[i])%d], dp[i][j][z]+a[i]);
			}
		}
	}
	cout << dp[n][k][0] << endl;
}