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
	ull n,k,p;
	cin>>n>>k;
	vector<pair<ull,ull> > a(n+1);
	rep(i,n)cin>>a[i+1].first>>a[i+1].second;
	a[0].first=0;a[0].second=0;
	sort(a.begin(),a.end());
	ll mon = k;
	rep(i,n){
		p = a[i+1].first;
		mon -= (a[i+1].first-a[i].first);
		//cout << mon << endl;
		if(mon<0){
			mon += a[i+1].first-a[i].first;
			cout << a[i].first + mon << endl;
			return 0;
		}
		mon += a[i+1].second;
/*
		cout << "debug start" << endl;
		cout << p << endl;
		cout << mon << endl;
		cout << "debug end" << endl;
		*/
	}
	//cout << "abc" << endl;
	cout << p+mon << endl;
}