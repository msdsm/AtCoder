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

ld ans = numeric_limits<ld>::max();

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	cout<<fixed<<setprecision(20);
	ll a,b;
	cin >> a >> b;
	ld p = ld(2)/3;
/*
	cout << "debug start" << endl;
	cout << powl(25,p) << endl;
	cout << "debug end" << endl;
*/	
	ld tmp = powl(ld(a/b/2),p);
	ll x = ll(tmp);
	for(ll i = -10; i < 10; i++){
		ll argmin = x + i;
		if(argmin<0)
			continue;
		ld min = b * argmin + a/sqrt(1+argmin);
		if(ans>min){
			ans = min;
		}
	}
	cout << ans << endl;
}