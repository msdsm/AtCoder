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
	ll n;
	cin >> n;
	vector<ll> a(n),b(n);
	rep(i,n)cin >> a[i] >> b[i];
	ll min = a[0]+b[0];
	rep(i,n){
		ll tmp = a[i];
		rep(j,n){
			if(i==j)
				tmp+=b[j];
			else
				tmp=max(tmp,b[j]);
			if(tmp<min)
				min=tmp;
			tmp=a[i];
		}
	}
	cout << min << endl;
}