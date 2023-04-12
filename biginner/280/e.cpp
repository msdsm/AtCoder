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

/*nCr 高速*/
/*使い方
下の変数、関数2つをmain関数外に貼る
main関数内で一番最初にbinom_init()を呼び出しセットする
nCrを使いたい時にbinom(n,r)で参照可能
/*ここから*/
vector<ll> fac,finv,inv;
ll MAX = 1000000;
ll MOD = mod;
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
/*ここまでをmain関数外に貼り付ける*/

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
	binom_init();
	ll n,p;
	cin >> n >> p;
	ll q = 100-p;
	if(p==0){
		cout << n << endl;
		return 0;
	}
	if(p==100){
		if(n%2==0)
			cout << n/2 << endl;
		else
			cout << n/2+1 << endl;
		return 0;
	}
	//合計をn-1にする
	ll x = 0;
	ll y = n-1;
	ll PP = 1;
	ll QQ = 1;
	ll mp = 1;
	ll mq = 1;
	ll inv100 = modinv(ll(100), mod)%mod;
	ll invq = modinv(ll(100-p), mod)%mod;
	invq *= invq;
	invq %= mod;//100-pの2乗の逆元
	rep(i,n-1){
		QQ *= ll(100-p);
		QQ %= mod;
		mq *= inv100;
		mq %= mod;
	}
	while(x>=0&&y>=0){
		ll tmp = binom(x+y,x)%mod;

		tmp *= PP;
		tmp %= mod;
		tmp *= mp;
		tmp %= mod;
		tmp *= QQ;
		tmp %= mod;
		tmp *= mq;
		tmp %= mod;
		tmp *= (x+y+1)%mod;
		tmp %= mod;
		ans += tmp;
		ans %= mod;
		//終わり

		x += 1;
		y -= 2;
		PP *= p;
		PP %= mod;
		mp *= inv100;
		mp %= mod;
		QQ *= invq;
		QQ %= mod;
		mq *= ll(10000);
		mq %= mod;
	}



	//合計をn-2にする
	x = 0;
	y = n-2;
	PP = 1;
	QQ = 1;
	mp = 1;
	mq = 1;
	inv100 = modinv(ll(100), mod)%mod;
	invq = modinv(ll(100-p), mod)%mod;
	invq *= invq;
	invq %= mod;//100-pの2乗の逆元
	rep(i,n-2){
		QQ *= ll(100-p);
		QQ %= mod;
		mq *= inv100;
		mq %= mod;
	}
	while(x>=0&&y>=0){
		ll tmp = binom(x+y,x)%mod;

		tmp *= PP;
		tmp %= mod;
		tmp *= mp;
		tmp %= mod;
		tmp *= QQ;
		tmp %= mod;
		tmp *= mq;
		tmp %= mod;
		tmp *= (x+y+1)%mod;
		tmp %= mod;
		tmp %= mod;
		tmp *= p;
		tmp %= mod;
		tmp *= inv100;
		ans += tmp;
		ans %= mod;
		//終わり

		x += 1;
		y -= 2;
		PP *= p;
		PP %= mod;
		mp *= inv100;
		mp %= mod;
		QQ *= invq;
		QQ %= mod;
		mq *= ll(10000);
		mq %= mod;
	}
	cout << ans << endl;
}