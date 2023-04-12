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
ll sum;

int main(){
	//cout << mod << endl;
	ll n;
	cin >> n;
	ll a[n];
	cinf(a,n);
	rep(i,n-1){
		arep(i+1,j,n){
			sum+=(a[i]%mod)*(a[j]%mod)%mod;
			sum%=mod;
		}
	}
	cout << sum << endl;
}