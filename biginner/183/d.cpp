#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int wa[200010];

int main(){
	ll n;
	cin >> n;
	ll w;
	cin >> w;
	ll s[n],t[n],p[n];
	rep(i,n){
		cin >> s[i] >> t[i] >> p[i];
		arep(s[i],j,t[i]){
			wa[j]+=p[i];
			if(wa[j]>w){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}