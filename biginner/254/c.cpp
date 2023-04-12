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
	vector<ll> a(n);
	cinf(a,n);
	if(k==1){
		cout << "Yes" << endl;
		return 0;
	}
	vector<vector<ll> > g(k);
	rep(i,n){
		g[i%k].push_back(a[i]);
	}
	rep(i,k){
		sort(g[i].begin(),g[i].end());
	}
	vector<ll> b(n);
	rep(i,n){
		b[i] = g[i%k][i/k];
	}
	rep2(1,i,n){
		if(b[i-1]<=b[i])
			continue;
		else{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}