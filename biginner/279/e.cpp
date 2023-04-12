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
	ll n,m;
	cin >> n >> m;
	vector<ll> a(m);
	cinf(a,m);
	vector<ll> ans(m);
	vector<ll> left(m);//最初空白
	left[0]=0;
	rep2(1,i,m){
		if(a[i-1]-1==left[i-1]){
			left[i] = left[i-1]+1;
		}else if(a[i-1]==left[i-1]){
			left[i] = left[i-1]-1;
		}else{
			left[i] = left[i-1];
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,m)cout<<left[i]<< ' ';
	cout << endl;
	cout << "debug end" << endl;
*/
	vector<ll> v(n);
	rep(i,n)v[i]=i+1;
	for(ll i=m-1;i>=0;i--){
		
		cout << "debug start" << endl;
		rep(i,n)cout << v[i] << endl;
		cout << "debug end" << endl;
		if(i==m-1){
			ans[i]=left[i]+1;
			continue;
		}
		swap(v[a[i+1]-1],v[a[i+1]]);

		
		
		ans[i] = v[left[i]];
	}
	rep(i,m){
		cout << ans[i] << endl;
	}
}