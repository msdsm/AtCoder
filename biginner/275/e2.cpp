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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m,k;
	cin >> n >> m >> k;
	vector<vector<ll> > dp(n+1);
	rep(i,n+1)dp[i].resize(k+1,0);
	dp[0][0]=1;
	rep(j,k){
		rep(i,n+1){
			/*
			cout<<"debug loop"<<endl;
			cout << i << endl;
			cout << j << endl;
			cout<<"loop end"<<endl;
			*/

			if(i==n){
				dp[i][j+1] += m * dp[i][j];
				dp[i][j+1]%=mod;
				continue;
			}
			rep(ttt,m){
				ll next = i+ttt+1;
				if(next>n){
					ll plus = next-n;
					next = n - plus;
				}
				dp[next][j+1] += dp[i][j];
				dp[next][j+1] %= mod;
			}
		}
	}
	/*
	cout << "あ" << endl;*/
	ll y = dp[n][k]%mod;
/*
	cout << "debug start" << endl;
	cout << y << endl;
	cout << "debug end" << endl;


	cout<<"debug start dp"<<endl;
	rep(j,k+1){
		rep(i,n+1){
			cout<<dp[i][j]<<' ';
		}cout<<endl;
	}
	cout<<"debud end dp"<<endl;
*/
	ll x = 1;
	rep(i,k){
		x*=m;
		x%=mod;
	}
	//cout << x << endl;
	cout << (y * modinv(x,mod))%mod << endl;
}