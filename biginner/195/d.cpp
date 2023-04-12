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

bool compare_by_second(pair<long long int,long long int> a,pair<long long int,long long int> b){
	if(a.second != b.second){
		return a.second < b.second;
	}else{
		return a.first < b.first;
	}
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int n,m,q;
	cin >> n >> m >> q;
	vector<pll> p(n);
	rep(i,n)cin>>p[i].first>>p[i].second;
	sort(p.begin(),p.end(),compare_by_second);
	
	reverse(p.begin(),p.end());
/*
	cout << "debug start" << endl;
	rep(i,n)
	cout << p[i].first << ' ' << p[i].second << endl;
	cout << "debug end" << endl;
*/
	vector<ll> x(m);
	rep(i,m)cin>>x[i];
	rep(t,q){
		int l,r;
		cin >> l >> r;
		ll ans = 0;
		vector<ll> y(m);
		rep(i,m)y[i]=x[i];
		rep2(l-1,i,r)y[i]=0;
		ll min = 1e7;
		ll maxj=0;
		rep(i,n){
			rep(j,m){
				if(y[j]>=p[i].first){
					if(min>y[j]){
						min=y[j];
						maxj=j;
					}
				}
			}
			if(min!=1e7){
				ans+=p[i].second;
				y[maxj]=0;
			}
			min=1e7;
		}
		cout << ans << endl;
	}
}