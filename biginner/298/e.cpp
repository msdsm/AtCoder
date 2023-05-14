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

ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,a,b,p,q;
	cin >> n >> a >> b >> p >> q;
	a--;
	b--;
	ll invp = modinv(p,mod);
	ll invq = modinv(q,mod);
	vector<vector<vector<ll> > > dp(n);
	rep(i,n)dp[i].resize(n);
	rep(i,n){
		rep(j,n){
			dp[i][j].resize(2, 0);
		}
	}
	dp[a][b][0]=1;
	rep(i,n-1){
		rep(j,n-1){
			rep(k,2){
				if(dp[i][j][k]!=0){//遷移
					if(k==0){//次高橋
						rep(dx,p){
							dp[min(i+dx+1, n-1)][j][1-k] += (dp[i][j][k]*invp)%mod;
							dp[min(i+dx+1, n-1)][j][1-k] %= mod;
						}
					}else{//次青木
						rep(dx,q){
							dp[i][min(j+dx+1, n-1)][1-k] += (dp[i][j][k]*invq)%mod;
							dp[i][min(j+dx+1, n-1)][1-k] %= mod;
						}
					}
				}
			}
		}
	}
	rep(j,n-1){
		ans += dp[n-1][j][1];
		ans %= mod;
	}
	cout << ans << endl;
}