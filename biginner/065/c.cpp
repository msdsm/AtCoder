#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll mod = 1000000007;

using namespace std;

ll fact(ll num){
	ll f=1;
	while(num){
		f*=num%mod;
		f%=mod;
		num--;
	}
	return f;
}

int main(){
	ll n,m;
	cin >> n >> m;
	if(n-m==0)
		cout << fact(n)*fact(m)%mod*2%mod << endl;
	else if(n-m==1||n-m==-1)
		cout << fact(n)*fact(m)%mod << endl;
	else
		cout << 0 << endl;
}