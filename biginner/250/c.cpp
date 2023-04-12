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
	vector<ll> ans(n);
	rep(i,n)ans[i]=i+1;
	map<ll,ll> mp;
	rep(i,n){
		mp[i+1]=i;
	}
	rep(i,q){
		ll x;
		cin >> x;
		ll tmp = mp[x];
		if(tmp==n-1){
			ll tmp1 = ans[tmp];
			ll tmp2 = ans[tmp-1];
			ans[tmp] = tmp2;
			ans[tmp-1] = tmp1;
			mp[tmp2] = tmp;
			mp[tmp1] = tmp-1;
		}else{
			ll tmp1 = ans[tmp];
			ll tmp2 = ans[tmp+1];
			ans[tmp] = tmp2;
			ans[tmp+1] = tmp1;
			mp[tmp2] = tmp;
			mp[tmp1] = tmp+1;
		}
/*
		cout << "debug start" << endl;
		rep(i,n){
		if(i==n-1)
			cout << ans[i] << endl;
		else
			cout << ans[i] << ' ';
	}
		cout << "debug end" << endl;
*/		
		
	}
	rep(i,n){
		if(i==n-1)
			cout << ans[i] << endl;
		else
			cout << ans[i] << ' ';
	}
}