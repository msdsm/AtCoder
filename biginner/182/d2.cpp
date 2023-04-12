#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
#define max(a,b) ((a)>(b)?(a):(b))
#define max3(a,b,c) ((a)>max(b,c)?(a):max(b,c))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll ans;

int main(){
	ll n;
	cin >> n;
	ll a[n];
	cinf(a,n);
	ll p[n];
	ll q[n];
	p[0]=a[0];
	arep(1,i,n){
		p[i]=p[i-1]+a[i];
	}
rep(i,n){
cout << p[i] << endl;
}
	q[0]=max(a[0],0);
	arep(1,i,n){
		q[i]=max3(p[i-1],p[i-1]+a[i],0);
	}
rep(i,n){
cout << q[i] << endl;
}
	ll x=0;
	rep(i,n){
		ans = max(ans,x+q[i]);
		x = x+p[i];
	}
	cout << ans << endl;
}