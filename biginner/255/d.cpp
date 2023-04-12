//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
#define fst first
#define snd second
#define pcin(x,n) for(ll i=0;i<(n);i++)cin>>x[i].fst>>x[i].snd;
#define pdebug(x) cout << '(' << x.fst << ',' << x.snd << ")\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,q;
	cin >> n >> q;
	vector<ll> a(n);
	cinf(a,n);
	sort(a.begin(),a.end());
	vector<ll> s(n+1);
	s[0]=0;
	rep(i,n){
		s[i+1] = s[i]+a[i];
	}
	while(q--){
		ll x;
		cin >> x;
		ll index = lower_bound(a.begin(),a.end(),x)-a.begin();
		cout << x*index-s[index] + s[n]-s[index]-x*(n-index) << endl;
	}
}