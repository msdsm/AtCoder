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

bool f(ll x){
	if(x%2==0){
		if(x%3==0 || x%5==0)
			return true;
		else
			return false;
	}
	return true;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	rep(i,n){
		if(!f(a[i])){
			cout << "DENIED" << endl;
			exit(0);
		}
	}
	cout << "APPROVED" << endl;
}