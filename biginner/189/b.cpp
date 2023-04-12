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

double sum;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	double x;
	cin >> n >> x;
	vector<ll> v(n),p(n);
	rep(i,n)cin >> v[i] >> p[i];
	rep(i,n){
		sum+=static_cast<double>(v[i])*static_cast<double>(p[i])/100;
		if(sum>x){
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}