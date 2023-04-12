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
ll ans;

ll f(ll x){
	ll ret = 1;
	rep(i,x){
		ret*=10;
		ret%=mod;
	}
	return (ret+mod-1)%mod;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	ll d=0;
	ll m = n;
	while(m){
		m/=10;
		d++;
	}
	//cout << d << endl;
	ll num = 9;
	rep(i,d-1){
		ans += (num%mod)*((num+1)%mod)/2;
		ans %= mod;
		num*=10;
	}
	//cout << ans << endl;
	num = n-f(d-1);
	ans += (num%mod)*((num+1)%mod)/2;
	ans %= mod;
	cout << ans << endl;
}