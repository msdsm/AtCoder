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
	ll x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	vector<ll> g0(k+1),g1(k+1),g2(k+1),g3(k+1);
	if(x1==x2&&y1==y2){
		g0[0]=1;
	}else if(x1==x2){
		g1[0]=1;
	}else if(y1==y2){
		g2[0]=1;
	}else{
		g3[0]=1;
	}
	rep(i,k){
		g0[i+1]=g1[i]+g2[i];
		g1[i+1]=((((w-1+MOD)%MOD)*g0[i])%MOD + (((w-2+MOD)%MOD)*g1[i])%MOD)%MOD + g3[i];
		g2[i+1]=((((h-1+MOD)%MOD)*g0[i])%MOD + (((h-2+MOD)%MOD)*g2[i])%MOD)%MOD + g3[i];
		g3[i+1]=((((w-1+MOD)%MOD)*g2[i])%MOD + (((h-1+MOD)%MOD)*g1[i])%MOD)%MOD + (((h+w-4+MOD)%MOD)*g3[i])%MOD;
		g0[i+1]%=MOD;
		g1[i+1]%=MOD;
		g2[i+1]%=MOD;
		g3[i+1]%=MOD;
	}
	cout << g0[k] << endl;
}