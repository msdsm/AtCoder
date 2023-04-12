#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt;

int main(){
	ll n;
	cin >> n;
	ll a[n];
	cinf(a,n);
	arep(1,i,n){
		if(a[i]<a[i-1]){
			cnt+=a[i-1]-a[i];
			a[i]=a[i-1];
		}
	}
	cout << cnt << endl;
}