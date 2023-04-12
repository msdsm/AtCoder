#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll sum=0;

int main(){
	ll n,k;
	cin >> n >> k;
	ll l[n];
	cinf(l,n);
	sort(l,l+n);
	rep(i,k){
		sum+=l[n-i-1];
	}
	cout << sum << endl;
}