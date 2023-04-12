#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	ll n;
	cin >> n;
	ll x[n];
	cinf(x,n);
	ll r1=abs(x[0]);
	double r2=x[0]*x[0];
	ll r3=abs(x[0]);
	arep(1,i,n){
		r1+=abs(x[i]);
		r2+=x[i]*x[i];
		if(r3<abs(x[i]))
			r3=abs(x[i]);
	}
	cout << r1 << endl;
	cout << setprecision(20) << sqrt(r2) << endl;
	cout << r3 << endl;
}