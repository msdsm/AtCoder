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
	ll t;
	cin >> t;
	while(t--){
		ll n,m;
		cin >> n >> m;
		vector<pll> p(n);
		pcin(p,n);
		vector<ll> b(n);
		b[0]=p[0].fst*p[0].snd;
		rep2(1,i,n){
			b[i] = b[i-1] + p[i].fst*p[i].snd;
		}
		vector<ll> a(n);
		a[0] = b[0];
		ll max = -1e6;
		if(max<a[0])
			max=a[0];
		rep2(1,i,n){
			a[i] = a[i-1]+b[i];
			if(max<a[i])
				max=a[i];
		}
		cout << max << endl;
	}
}