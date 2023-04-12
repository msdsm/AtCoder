#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll delta(ll x,ll l,ll r,ll p){
	if(x<r&&x>=l)
		return p;
	else
		return 0;
}

ll tmp;

int main(){
	ll n;
	cin >> n;
	ll w;
	cin >> w;
	ll s[n],t[n],p[n];
	rep(i,n){
		cin >> s[i] >> t[i] >> p[i]; 
	}

	rep(i,200010){
		tmp=0;
		rep(j,n){
			tmp+=delta(i,s[j],t[j],p[j]);
		}
		if(tmp>w){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
