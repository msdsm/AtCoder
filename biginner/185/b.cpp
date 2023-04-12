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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n,m,t;
	cin >> n >> m >> t;
	ll maxn = n;
	vector<ll> a(m),b(m);
	rep(i,m){
		cin >> a[i] >> b[i];
	}

	n -= a[0];
	if(n<=0){cout << "No" << endl; return 0;}
	n += b[0]-a[0];
	if(n>maxn)n=maxn;
	arep(1,i,m){
		n -= a[i]-b[i-1];
		if(n<=0){cout << "No" << endl; return 0;}
		n += b[i]-a[i];
		if(n>maxn)n=maxn;
	}
	n -= t-b[m-1];
	if(n<=0){cout << "No" << endl; return 0;}
	cout << "Yes" << endl;
}