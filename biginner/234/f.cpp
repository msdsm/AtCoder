//abc234f Reordering

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

ll MOD = 998244353;
ll MAX = 5010;
ll ans;

vector<ll> fac,finv,inv;

void binom_init() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
ll binom(ll n, ll r){
    if(n<r || n<0 || r<0) return 0;
    return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}

int main(){
	binom_init();
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	string s;
	cin >> s;
	ll n = s.length();
	vector<ll> freq(26);
	rep(i,n){
		freq[s[i]-'a']++;
	}
/*
	cout << "debug start" << endl;
	rep(i,26)cout << freq[i] << endl;
	cout << "debug end" << endl;
*/
	
	vector<vector<ll> > dp(26);
	rep(i,26)dp[i].resize(n);

	rep(j,n){
		if(j+1<=freq[0])
			dp[0][j]=1;
		else
			dp[0][j]=0;
	}
	rep2(1,i,26){
		if(freq[i]>0)
			dp[i][0]=dp[i-1][0]+1;
		else
			dp[i][0]=dp[i-1][0];
	}
	rep2(1,i,26){
		rep2(1,j,n){
			ll tmp = max((ll)0,j-freq[i]);
/*
if(i==1&&j==1){

	cout << "debug start" << endl;
	cout << dp[i][j] << endl;
	cout << tmp << endl;
	rep2(tmp,k,j+1){
		cout << k << ':' << endl;
				cout << dp[i-1][k] << endl;
				cout << combination2(j+1,j-k) << endl;
				
			}
	cout << "debug end" << endl;
	
	
}
*/

			rep2(tmp,k,j+1){
				dp[i][j] += (dp[i-1][k]%MOD)*(binom(j+1,j-k)%MOD);
				dp[i][j] %= MOD;
			}
			if(freq[i]>=j+1)
				dp[i][j] = (dp[i][j]+1)%MOD;
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,26){
		rep(j,n){
			cout << dp[i][j] << ' ';
		}
		cout  << endl;
	}
	cout << "debug end" << endl;
*/	
	
	rep(j,n){
		ans += dp[25][j];
		ans %= MOD;
	}
	cout << ans << endl;
}