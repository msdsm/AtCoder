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
	ll n,m;
	cin >> n >> m;
	ll a[m];
	ll b[m];
	rep(i,m){
		cin >> a[i] >> b[i];
	}
	bool one[n],second[n];
	rep(i,n){
		one[i]=false;
		second[i]=false;
	}
	rep(i,m){
		if(a[i]==1)
			one[b[i]-1]=true;
		if(b[i]==n)
			second[a[i]-1]=true;
	}
	rep(i,n){
		if(one[i]&&second[i]){
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}