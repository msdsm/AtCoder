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
	vector<ll> a(n+1);
	vector<ll> b(m+1);
	vector<ll> c(n+m+1);
	cinf(a,n+1);
	cinf(c,n+m+1);
	rep(i,m+1){
		ll tmp = 0;
		rep2(1,j,min(n,i)+1){
			tmp += a[n-j]*b[m-i+j];
		}
		b[m-i] = (c[n+m-i]-tmp)/a[n];
	}
	rep(i,m){
		cout << b[i] << ' ';
	}
	cout << b[m] << endl;
}