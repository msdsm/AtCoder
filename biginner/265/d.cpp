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
	ll n,p,q,r;
	cin >> n >> p >> q >> r;
	vector<ll> a(n);
	cinf(a,n);
	vector<ll> s(n+1);
	s[0]=0;
	rep2(1,i,n+1)s[i]=s[i-1]+a[i-1];

	rep(i,n){
		ll idx = i;
		ll idy = lower_bound(s.begin(),s.end(),p+s[idx])-s.begin();
		if(idy==n+1)continue;
		if(s[idy]-s[idx]!=p)continue;
		ll idz = lower_bound(s.begin(),s.end(),q+s[idy])-s.begin();
		if(idz==n+1)continue;
		if(s[idz]-s[idy]!=q)continue;
		ll idw = lower_bound(s.begin(),s.end(),r+s[idz])-s.begin();
		if(idw==n+1)continue;
		if(s[idw]-s[idz]!=r)continue;
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}