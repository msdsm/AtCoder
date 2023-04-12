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
	vector<pll> p(m);
	vector<vector<ll> > path(n);
	vector<ll> in(n);
	pcin(p,m);
	rep(i,m){
		p[i].fst--;
		p[i].snd--;
		path[p[i].fst].push_back(p[i].snd);
		in[p[i].snd]++;
	}
	ll cnt = 0;
	ll start;
	rep(i,n){
		if(in[i]==0){
			cnt++;
			start = i;
		}
	}
	if(cnt!=1){
		cout << "No" << endl;
		return 0;
	}
	stack<pll> s;//node, value
}