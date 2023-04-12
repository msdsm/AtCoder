#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll t[101],p[101],x[101];
ll sum;

int main(){
	ll n,m;
	cin >> n;
	cinf(t,n);
	rep(i,n){
		sum+=t[i];
	}
	cin >> m;
	rep(i,m){
		cin >> p[i] >> x[i];
	}
	rep(i,m){
		cout << sum-t[p[i]-1]+x[i] << endl;
	}
}