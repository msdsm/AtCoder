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
	ll n,s,d;
	cin >> n >> s >> d;
	vector<ll> x(n),y(n);
	rep(i,n){
		cin >> x[i] >> y[i];
	}
	rep(i,n){
		if(x[i]<s && y[i]>d){
			cout << "Yes" << endl;
			exit(0);
		}
	}
	cout << "No" << endl;
}