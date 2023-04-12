#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll mod = 1e9+7;

ll f(ll x,ll n){//x^n
	ll tmp=1;
	rep(i,n){
		tmp*=x;
		tmp%=mod;
	}
	return tmp;
}

int main(){
	//cout << mod << endl;
	ll n;
	cin >> n;
	cout << (f(10,n)+f(8,n)-2*f(9,n)%mod+mod)%mod << endl;
}