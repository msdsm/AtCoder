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
	ll a[n];
	cinf(a,n);
	ll min = a[0];
	ll max = a[0];
	arep(1,i,n){
		if(max<a[i])
			max=a[i];
		else if(min>a[i])
			min=a[i];
	}
	cout << max-min << endl;
}