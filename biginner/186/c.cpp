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

ll cnt;

bool f(ll x,ll m){
	while(x){
		if(x%m==7)
			return false;
		x/=m;
	}
	return true;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	cin >> n;
	arep(1,i,n+1){
		if(f(i,8)&&f(i,10))
			cnt++;
	}
	cout << cnt << endl;
}