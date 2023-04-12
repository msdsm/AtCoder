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
	ll n,q;
	cin >> n >> q;
	vector<ll> a(n);
	cinf(a,n);
	sort(a.begin(),a.end());
	rep(t,q){
		ll k;
		cin >> k;
		auto f = [&](ll x){//Tからboolへの写像が広義単調増加
		if(a[x]>=k)
			return true;
		else
			return false;
	};
		ll ng = -1;
		ll ok = n;
		while(ok - ng > 1){
			ll mid = (ng + ok) / 2;
			(f(mid) ? ok : ng) = mid;
		}

		if(ok == n)
			cout << k+n << endl;
		else
			cout << k+ok << endl;
	}
}