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
	ll n,m,t;
	cin >> n >> m >> t;
	vector<ll> a(n-1);
	cinf(a,n-1);
	vector<ll> x(m),y(m);
	rep(i,m)cin>>x[i]>>y[i];
	vector<ll> bo(n, 0);
	rep(i,m){
		bo[x[i]-1] = y[i];
	}
	ll rem = t;
	rep(i,n-1){
		rem += bo[i];
		if(rem>a[i]){
			rem -= a[i];
		}else{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}