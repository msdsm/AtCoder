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

ld ans = numeric_limits<ld>::max();

ld d(ll x1, ll y1, ll x2, ll y2){
	ll sum = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return sqrt(sum);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<pll> ci(n);//まち
	vector<pll> tr(m);//宝
	pcin(ci,n);
	pcin(tr,m);
	vector<ll> v(n);
	rep(i,n)v[i]=i;

	//宝なし最短
	do{
		ld sum = 0.0;
		pll pre = pll(0,0);
		ll sp = 1;
		rep(i,n){
			pll now = ci[v[i]];
			sum += d(pre.fst,pre.snd,now.fst,now.snd)/sp;
			pre = now;
		}
		sum += d(pre.fst,pre.snd,ll(0),ll(0))/sp;
		if(sum<ans)
			ans = sum;
	}while(next_permutation(v.begin(),v.end()));
	cout << ans << endl;
}