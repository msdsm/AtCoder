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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll a,b,c,d;
	cin >> a >> b >> c >> d;

	auto f = [&](ll x){
		ll start;
		if(a%x)
			start = a + x-a%x;
		else
			start = a;
		//cout << start << endl;
		if(b-start<0)
			return (ll)0;
		return (ll)1+((ll)b-start)/x;
	};

/*
	cout << "debug start" << endl;
	cout << f(c) << endl;
	cout << f(d) << endl;
	cout << f(a/__gcd(c,d)*b) << endl;
	cout << "debug end" << endl;
*/	
	

	cout << b-a+1-f(c)-f(d)+f(c/__gcd(c,d)*d) << endl;
}