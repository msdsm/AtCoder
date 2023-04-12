#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ull sum;
ll ans;
ll l;
ll k;

int main(){
	ull x,y;
	ll a,b;
	cin >> x >> y >> a >> b;
	if(static_cast<ll>((log(y)-log(x))/log(a))==(log(y)-log(x))/log(a)){
		l = static_cast<ll>((log(y)-log(x))/log(a))-1;
		if(l<0)
			l=0;
	}
	else{
		l = static_cast<ll>((log(y)-log(x))/log(a));
		if(l<0){
			l=0;
		}
	}


	if(static_cast<ll>(1+(log(b)-log(a-1)-log(x))/log(a))==1+(log(b)-log(a-1)-log(x))/log(a)){
		k = static_cast<ll>(1+(log(b)-log(a-1)-log(x))/log(a))-1;
		if(k<0){
			k=0;
		}
	}
	else{
		k = static_cast<ll>(1+(log(b)-log(a-1)-log(x))/log(a));
		if(k<0)
			k=0;
	}


	if(k>=l&&k!=0)
		cout << l << endl;
	else{
		ld tmp=k+static_cast<ld>(y-1)/b-static_cast<ld>(x)/b-static_cast<ld>(pow(a,k))/b;
		cout << static_cast<ll>(tmp) << endl;
	}
}