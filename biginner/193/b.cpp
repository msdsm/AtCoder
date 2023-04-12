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

bool flag;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll min = 100000000000;
	ll n;
	cin >> n;
	vector<ll> a(n),p(n),x(n);
	rep(i,n)cin >> a[i] >> p[i] >> x[i];
	rep(i,n){
		if(a[i]<x[i] && min > p[i]){
			min = p[i];
			flag = true;
		}
	}
	if(flag)
		cout << min << endl;
	else
		cout << -1 << endl;
}