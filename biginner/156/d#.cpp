#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
#define mod 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll combination(ll n,ll k){
  if(n==k || n==0 || n==1 || k==0)
    return 1;
  else
    return (combination(n-1,k)+combination(n-1,k-1));
}

ll f(ll x,ll y){
	ll f=1;
	rep(i,y){
		f*=x;
		f%=mod;
	}
	return f;
}

int main(){
	ll n,a,b;
	cin >> n >> a >> b;
	ll ans;
	ans = f(2,n)%mod-1-combination(n,a)%mod-combination(n,b)%mod;
	ans%=mod;
	cout << ans << endl;
}