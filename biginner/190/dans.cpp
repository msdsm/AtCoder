//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt1;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	cin >> n;
	while(n%2==0){
		n/=2;
	}
	for(ll i=1;i*i<=n;i++){
		if(n%i==0)
			cnt1++;
	}
	cnt1*=2;
	if(static_cast<ld>(sqrt(n))==static_cast<ll>(sqrt(n)))cnt1--;
	cout << 2*cnt1 << endl;
}