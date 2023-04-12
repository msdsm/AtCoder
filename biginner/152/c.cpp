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

ll cnt=1;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	cin >> n;
	vector<ll> p(n);
	cinf(p,n);
	ll min = p[0];
	arep(1,i,n){
		if(p[i]<=min){
			cnt++;
			min = p[i];
		}
	}
	cout << cnt << endl;
}