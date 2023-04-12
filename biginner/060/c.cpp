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

int main(){
	ll n,T;
	cin >> n >> T;
	ll t[n];
	cinf(t,n);
	arep(1,i,n){
		if(T>t[i]-t[i-1])
			sum+=t[i]-t[i-1];
		else
			sum+=T;
	}
	cout << sum+T << endl;
}