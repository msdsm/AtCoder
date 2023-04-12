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
	vector<vector<ll> > a(n);
	rep(i,n){
		a[i].resize(i+1);
	}
	rep(i,n){
		rep(j,a[i].size()){
			if(j==0 || j==i)
				a[i][j] = 1;
			else
				a[i][j] = a[i-1][j-1]+a[i-1][j];
		}
	}
	rep(i,n){
		rep(j,a[i].size()){
			if(j!=a[i].size()-1)
				cout << a[i][j] << ' ';
			else
				cout << a[i][j] << endl;
		}
	}
}