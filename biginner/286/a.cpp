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
	ll n,p,q,r,s;
	cin >> n >> p >> q >> r >> s;
	vector<ll> a(n);
	cinf(a,n);
	rep(i,p-1){
		cout << a[i] << ' ';
	}
	rep(i,q-p+1){
		cout << a[r-1+i] << ' ';
	}
	rep(i,r-q-1){
		cout << a[i+q] << ' ';
	}
	rep(i,s-r+1){
		cout << a[p-1+i] << ' ';
	}
	rep(i,n-s){
		cout << a[s+i] << ' ';
	}cout<<endl;
}