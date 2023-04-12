//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	cinf(a,n);
	vector<ll> b(n);
	vector<pll> c(n);
	rep(i,n)b[i]=a[i];
	sort(a.begin(),a.end());

	rep(i,n)c[i].first = b[i];
	rep(i,n){
		c[i].second = lower_bound(a.begin(),a.end(),c[i].first) - a.begin();
	}
	ll cnt = k/n;
	ll max = k%n;
	rep(i,n){
		if(c[i].second<max)
			cout << cnt+1 << endl;
		else
			cout << cnt << endl;
	}
}