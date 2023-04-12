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
	ll n,l,r;
	cin >> n >> l >> r;
	vector<ll> a(n);
	cinf(a,n);
	vector<ll> s(n);
	s[0] = a[0];
	rep2(1,i,n)s[i]=s[i-1]+a[i];
	vector<ll> f(n+1);
	f[n] = s[n-1];
	rep(i,n){
		if(i==n-1)
			f[n-i-1] = min(f[n-i], r*(i+1));
		else
			f[n-i-1] = min(f[n-i],s[n-i-2]+r*(i+1));
	}
	ll ans=0;
	rep(i,n)ans+=a[i];
	rep(i,n+1){
		ll tmp;
		if(i==0)
			tmp = f[0];
		else
			tmp = l*i - s[i-1] + f[i];
		if(tmp<ans)ans=tmp;
	}
	cout << ans << endl;
}