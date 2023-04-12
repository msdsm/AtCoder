#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
#define mod 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

/*nCk*/
ll combination(ll n,ll k){
  if(n==k || n==0 || n==1 || k==0)
    return 1;
  else
    return (combination(n-1,k)+combination(n-1,k-1));
}

int main(){
	ll n,a,b;
	cin >> n >> a >> b;
	ll sum=0;
	arep(1,i,n+1){
		sum+=(combination(n,i)%mod);
		sum%=mod;
	}
	sum=sum-combination(n,a)%mod-combination(n,b)%mod;
	sum%=mod;
	if(sum<=0)
		cout << '0' << endl;
	else 
		cout << sum << endl;
}