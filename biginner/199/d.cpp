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

ull cnt;
ull dep;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<pii> e(m);
	rep(i,m)cin >> e[i].first >> e[i].second;
	vector<set<int>> v(n);
	rep(i,m){
		v[e[i].first-1].insert(e[i].second);
		v[e[i].second-1].insert(e[i].first);
	}
	rep(i,n){
		if(v[i].size()>=3){
			cout << 0 << endl;
			return 0;
		}
	}

	rep(i,n){
		if(v[i].size()==0)
			dep++;//独立
	}
	cout << powl(3,dep) << endl;
}