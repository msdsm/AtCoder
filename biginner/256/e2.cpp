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
	ll n;
	cin >> n;
	vector<ll> x(n),c(n);
	cinf(x,n);
	rep(i,n)x[i]--;
	cinf(c,n);
	vector<ll> cost(n);
	rep(i,n){
		cost[x[i]]+=c[i];
	}
	vector<ll> p(n);//iが何番目にあるか
	ll ans = 0;
	vector<pll> v(n);
	rep(i,n){
		v[i].fst = cost[i];
		v[i].snd = i;
	}
	sort(v.begin(),v.end());
	rep(i,n){
		p[v[i].snd] = i;
	}
	rep(i,n){
		if(p[i]>p[x[i]])
			ans += c[i];
	}
	cout << ans << endl;
}