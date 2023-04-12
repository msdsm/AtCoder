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
	ll mod =  998244353;
	ll a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	a %= mod;
	b %= mod;
	c %= mod;
	d %= mod;
	e %= mod;
	f %= mod;
	ll x = a*b;
	x %= mod;
	x *= c;
	x %= mod;
	ll y = d*e;
	y %= mod;
	y *= f;
	y %= mod;
	//cout << x << endl;
	//cout << y << endl;
	ll ans = x + mod - y;
	ans %= mod;
	cout << ans << endl;
}