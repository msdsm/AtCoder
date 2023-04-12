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

ll inf = numeric_limits<ll>::max();

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	vector<string> s(n);
	cinf(s,n);
	vector<vector<ll> > p(n);

	vector<vector<pll> > ans(n);//(最短距離、-(最大のそうわ))
	rep(i,n)ans[i].resize(n);

	rep(i,n){
		rep(j,n){
			if(s[i][j]=='Y')
				ans[i][j] = pll(1,0);
			else
				ans[i][j] = pll(inf,0);
		}
	}
	rep(k,n){
		rep(i,n){
			rep(j,n){
				pll tmp;
				if(ans[i][k].fst!=inf&&ans[k][j].fst!=inf){
					tmp.fst = ans[i][k].fst + ans[k][j].fst;
					tmp.snd = ans[i][k].snd - a[k] + ans[k][j].snd;
					if(tmp<ans[i][j])
						ans[i][j]=tmp;
				}
			}
		}
	}

	ll q;
	cin >> q;
	while(q--){
		ll u,v;
		cin >> u >> v;
		u--;v--;
		if(ans[u][v].fst==inf)
			cout << "Impossible" << endl;
		else
			cout << ans[u][v].fst << ' ' << a[u]-ans[u][v].snd+a[v] << endl;
	}
}