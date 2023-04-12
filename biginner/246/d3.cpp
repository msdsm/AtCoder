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
	ll n;
	cin >> n;
	ll a,tmp;
	ll ans;
	for(tmp=0;tmp*tmp*tmp<=n;tmp++){
		a = tmp;
	}
	ll b = 0;
	for(tmp=0;tmp*tmp*tmp<=n-a*a*a;tmp++){
		b = tmp;
	}
/*
	cout << "debug start" << endl;
	cout << a << ' ' << b << endl;
	cout << "debug end" << endl;
*/	
	
	while(true){
		tmp = a*a*a+a*a*b+a*b*b+b*b*b;
		if(tmp>=n){
			ans = tmp;
			break;
		}
	}
	a++;
	if(a*a*a>=n){
		if(ans>a*a*a)
			ans = a*a*a;
	}
	cout << ans << endl;
}