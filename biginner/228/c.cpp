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
	ll n,k;
	cin >> n >> k;
	vector<pll> a(n);
	rep(i,n){
		ll p1,p2,p3;
		cin >> p1 >> p2 >> p3;
		a[i].snd = i;
		a[i].fst = p1+p2+p3;
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
/*
	cout << "debug start" << endl;
	rep(i,n){
		cout << a[i].snd << ' ' << a[i].fst << endl;
	}
	cout << "debug end" << endl;
*/	
	
	ll sum = a[k-1].fst;
	vector<bool> ans(n);
	rep(i,k){
		ans[a[i].snd]=true;
	}
	rep2(k,i,n){
/*
		cout << "debug start" << endl;
		cout << sum << endl;
		cout << a[i].snd+300 << endl;
		cout << "debug end" << endl;
*/		
		
		if(a[i].fst+300 >= sum)
			ans[a[i].snd]=true;
		else
			ans[a[i].snd]=false;
	}
	rep(i,n){
		if(ans[i])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}