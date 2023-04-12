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
	ll n;
	cin >> n;
	ll a[n];
	ll b[n];
	rep(i,n){
		cin >> a[i] >> b[i];
	}
	rep(i,n){
		sum+=(b[i]-a[i]+1)*(a[i]+b[i])/2;
	}
	cout << sum << endl;
}