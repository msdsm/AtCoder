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

ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<ll> a(m),b(m);
	vector<vector<ll>> c(m);
	set<ll> ans;
	rep(i,m){
		cin >> a[i] >> b[i];
		rep(j,b[i]){
			int tmp;
			cin >> tmp;
			c[i].push_back(tmp);
		}
	}
	vector<set<ll>> d(n);
	rep(i,m){
		rep(j,b[i]){
			d[c[i][j]-1].insert(i);
		}
	}
	rep(i,n){
		if(d[i].size()==0){
			cout << -1 << endl;
			return 0;
		}
	}
	rep(i,n){
		if(d[i].size()==1){
			auto itr=d[i].begin();
			ans.insert(*itr)
			cnt+= a[*itr];
		}
	}
}