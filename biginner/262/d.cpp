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

ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll mod = 998244353;
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	rep(iii,n){//iii+1個選ぶ
		if(iii==0){
			ans += n;
			//cout << ans << endl;
			continue;
		}
		if(iii==n-1){
			ll sum = 0;
			rep(i,n)sum+=a[i];
			if(sum%n==0){
				ans++;
			}
			break;
		}
		vector<vector<vector<ll> > > dp(n);
		rep(i,n)dp[i].resize(iii+2);
		rep(i,n){
			rep(j,iii+2){
				dp[i][j].resize(iii+1,0);
			}
		}
		ll m = iii+1;
		dp[0][1][a[0]%m] = 1;
		dp[0][0][0] = 1;
		rep(i,n-1){
			rep(j,m+1){
				rep(k,m){
					/*if(i==1 && j==1 && k==0){

						cout << "debug start 1" << endl;
						cout << dp[i][j][k] << endl;
						cout << dp[i+1][j+1][(k+a[i+1])%m] << endl;
						cout << dp[i+1][j][k] << endl;
						cout << "debug end" << endl;
						
						
					}*/
					if(j+1<=m){
						dp[i+1][j+1][(k+a[i+1])%m] += dp[i][j][k]%mod;
						dp[i+1][j+1][(k+a[i+1])%m] %= mod;
					}
					dp[i+1][j][k] += dp[i][j][k]%mod;
					dp[i+1][j][k] %= mod;
					/*if(i==1 && j==1 && k==0){

						cout << "debug start 1" << endl;
						cout << dp[i][j][k] << endl;
						cout << dp[i+1][j+1][(k+a[i+1])%m] << endl;
						cout << dp[i+1][j][k] << endl;
						cout << "debug end" << endl;
						
						
					}*/
				}
			}
		}

		/*cout << "debug start" << endl;
		rep(i,n){
			cout << i << ':' << endl;
			rep(j,m+1){
				rep(k,m){
					cout << dp[i][j][k] << ' ';
				}
				cout<<endl;
			}
		}
		cout << "debug end" << endl;*/
		
		
		ans += dp[n-1][m][0]%mod;
		ans %= mod;
		//cout << ans << endl;
	}
	cout << ans << endl;
}