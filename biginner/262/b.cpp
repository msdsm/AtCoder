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

ll cnt;
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<vector<ll> > p(n);
	rep(i,n)p[i].resize(n, 0);
	rep(i,m){
		ll u, v;
		cin >> u >> v;
		u--;v--;
		p[u][v] = 1;
		p[v][u] = 1;
	}
	rep(i,n){
		rep2(i+1,j,n){
			rep2(j+1,k,n){
				if(p[i][j]==1 && p[j][k]==1 && p[k][i]==1){
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
}