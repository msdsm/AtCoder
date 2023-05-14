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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll q;
	cin >> q;
	ll mod = 998244353;
	ll inv10 = modinv(static_cast<ll>(10), mod);
/*
	cout << "debug start" << endl;
	cout << inv10 << endl;
	cout << "debug end" << endl;
*/	
	
	queue<ll> que;
	que.push(1);
	ll ans = 1;
	ll num = 1;//10^桁数
	while(q--){
		ll t;
		cin >> t;
		if(t==1){
			ll x;
			cin >> x;
			que.push(x);
			ans *= 10;
			ans %= mod;
			ans += x;
			ans %= mod;
			num *= 10;
			num %= mod;
		}else if(t==2){
			ll tmp = que.front();
			que.pop();
			ans = (ans-tmp*num+10*mod)%mod;
			num *= inv10;
			num %= mod;
		}else{
			cout << ans << endl;
		}
	}
}