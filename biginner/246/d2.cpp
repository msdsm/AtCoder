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
	if(n==0){
		cout << 0 << endl;
		return 0;
	}
	ll tmp;
	ll a,b;
	for(tmp=0;tmp*tmp*tmp*4<=n;tmp++){
		a = tmp;
		b = tmp;
	}

	cout << "debug start" << endl;
	cout << a << endl;
	cout << "debug end" << endl;
	
	
	ll ans = numeric_limits<ll>::max();
	rep(i,tmp+1){
		a = tmp+i;
		b = tmp-i;
		if(a*a*a+a*a*b+a*b*b+b*b*b>=n){
			if(a*a*a+a*a*b+a*b*b+b*b*b<ans)
				ans = a*a*a+a*a*b+a*b*b+b*b*b;
		}
	}
	rep(i,tmp){
		a = tmp+i;
		b = tmp-i-1;
		if(a*a*a+a*a*b+a*b*b+b*b*b>=n){
			if(a*a*a+a*a*b+a*b*b+b*b*b<ans)
				ans = a*a*a+a*a*b+a*b*b+b*b*b;
		}
	}
	rep(i,tmp+1){
		a = tmp+i+1;
		b = tmp-i;
		if(a*a*a+a*a*b+a*b*b+b*b*b>=n){
			if(a*a*a+a*a*b+a*b*b+b*b*b<ans)
				ans = a*a*a+a*a*b+a*b*b+b*b*b;
		}
	}
	cout << ans << endl;
}