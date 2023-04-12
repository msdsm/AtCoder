#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll ans=1;

int main(){
	ll mod = 1e9+7;
	ll n;
	cin >> n;
	arep(1,i,n+1){
		ans*=i;
		ans%=mod;
	}
	cout << ans << endl;
}