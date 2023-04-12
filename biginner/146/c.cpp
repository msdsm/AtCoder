//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;


ll digit(ll n){
	if(n==0)
		return 1;
	return 1+floor(log10(n));
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll a,b,x;
	cin >> a >> b >> x;

	//cout<<fixed<<setprecision(20);
	ll ng=0,ok=1e9+1;

	auto f = [&](ll c){
		if(a*c+b*digit(c)<=x)
			return false;
		else
			return true;
	};

	while(ok-ng>1){
		ll mid = (ng+ok)/2;
		(f(mid)?ok:ng)=mid;
	}
	if(ok==1e9+1)
		cout << 1000000000 << endl;
	else
		cout << ok-1 << endl;
}