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
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	cinf(a,n);
	set<ll> st[n-m+1];
	rep(i,n-m+1){
		rep(j,m){
			st[i].insert(a[i+j]);
		}
	}
	rep(i,n){
		rep(j,n-m+1){
			if(st[j].count(i)==0){
				cout << i << endl;
				return 0;
			}
		}
	}
}