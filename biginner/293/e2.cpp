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

map<ll,ll> mp;
ll f(ll a, ll x, ll mod){//a^x%m
	if(x%2==0){//偶数
		if(mp[x/2]==0){
			ll tmp = (mp[x/2] = f(a,x/2,mod));
			ll ret = tmp%mod;
			ret *= tmp%mod;
			ret %= mod;
			return ret;
		}else{
			ll tmp = mp[x/2];
			ll ret = tmp%mod;
			ret *= tmp%mod;
			ret %= mod;
			return ret;
		}
	}else{
		if(mp[(x-1)/2]==0){
			ll tmp = (mp[(x-1)/2] = f(a,(x-1)/2,mod));
			ll ret = tmp%mod;
			ret *= tmp%mod;
			ret %= mod;
			ret *= a%mod;
			ret %= mod;
			return ret;
		}else{
			ll tmp = mp[(x-1)/2];
			ll ret = tmp%mod;
			ret *= tmp%mod;
			ret %= mod;
			ret *= a%mod;
			ret %= mod;
			return ret;
		}
	}
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	mp[0]=1;
	ll a,x,m;
	cin >> a >> x >> m;
	mp[1]=a;
	if(a==1){
		cout << x%m << endl;
		return 0;
	}
	ll ans = modinv(a-1,m)%m;
	ans *= (f(a,x,m)-1+m)%m;
/*
	cout << "debug start" << endl;
	cout << (f(a,x,m)-1+m)%m << endl;
	cout << modinv(a-1,m) << endl;
	cout << "debug end" << endl;
*/
	ans %= m;
	cout << ans << endl;
}