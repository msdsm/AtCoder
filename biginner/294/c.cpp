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
	vector<ll> a(n);
	vector<ll> b(m);
	cinf(a,n);
	cinf(b,m);
	vector<ll> ansa(n);
	vector<ll> ansb(m);
	vector<pll> c(n+m);
	rep(i,n){
		c[i] = pll(a[i], i);
	}
	rep(i,m){
		c[i+n] = pll(b[i], i+n);
	}
	sort(c.begin(),c.end());
	rep(i,n+m){
		if(c[i].snd<n)
			ansa[c[i].snd] = i;
		else
			ansb[c[i].snd-n] = i;
	}
	rep(i,n)cout << ansa[i]+1 << ' ';
	cout<<endl;
	rep(i,m)cout << ansb[i]+1 << ' ';
	cout<<endl;
}