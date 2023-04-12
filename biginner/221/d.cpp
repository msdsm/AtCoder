#pragma GCC optimize("Ofast")
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<pll> p(n);
	vector<ll> ans(n);
	pcin(p,n);
	sort(p.begin(),p.end());
	ll min = p[0].fst;
	ll max = p[0].fst+p[0].snd;
	ll tmp;
	rep(i,n){
		tmp = p[i].fst+p[i].snd;
		if(tmp>max)
			max = tmp;
	}
	for(ll i = min; i < max; i++){
		ll mi = 0;
		ll ma = 0;
		while(p[mi].fst+p[mi].snd-1==i-1 && i>min)
			mi++;
		while(p[ma].fst==i)
			ma++;
		ans[ma-mi-1]++;
	}
	rep(i,n){
		cout << ans[i] << ' ';
	}
	cout << endl;
}