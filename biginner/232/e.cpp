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
ll MAX = 1000010;

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

ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	binom_init();
	ll h,w,k;
	cin >> h >> w >> k;
	w%=MOD;
	h%=MOD;
	ll x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	vector<ll> tmp1(k-1),tmp2(k-1);
	ll tmp3 = 1;
	ll tmp4 = h-1;
	tmp1[0] = (tmp3+tmp4)/h;
	rep2(1,i,k-1){
		tmp3 *= -1;
		tmp4 *= (h-1);
		tmp4%=MOD;
		tmp1[i] = ((tmp3+tmp4)/h);
	}
/*
	cout << "debug start tmp1" << endl;
	rep(i,k-1)cout << tmp1[i] << ' ';
	cout << endl;
	cout << "debug end" << endl;
*/	
	
	ll tmp5 = 1;
	ll tmp6 = w-1;
	tmp2[0] = (tmp5+tmp6)/w;
	rep2(1,i,k-1){
		tmp5 *= -1;
		tmp6 *= (w-1);
		tmp6%=MOD;
		tmp2[i] = ((tmp5+tmp6)/w);
	}
	/*
	cout << "debug start tmp2" << endl;
	rep(i,k-1)cout << tmp1[i] << ' ';
	cout << endl;
	cout << "debug end" << endl;
	*/
	rep(i,k-1){
		ans += (((tmp1[i]*tmp2[k-2-i])%MOD)*binom(k,i+1))%MOD;
/*
		cout << "debug start" << endl;
		cout << ans << endl;
		cout << "debug end" << endl;
*/		
		
	}
/*
	cout << "debug start" << endl;
	cout << ans << endl;
	cout << "debug end" << endl;
*/	
	
	if(x1==x2){
		tmp5 *= -1;
		tmp6 *= (w-1);
		tmp6%=MOD;
		ans += (tmp5+tmp6);
		ans /= w;
		ans%=MOD;
	}
	if(y1==y2){
		tmp3 *= -1;
		tmp4 *= (h-1);
		tmp4%=MOD;
		ans += (tmp3+tmp4);
		ans /= h;
		ans %= MOD;
	}
	cout << ans << endl;
}