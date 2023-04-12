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
	vector<vector<ll> > p(n);
	rep(i,m){
		ll a,b;
		cin >> a >> b;
		a--;
		b--;
		p[a].push_back(b);
		p[b].push_back(a);
	}
	ll Q;
	cin >> Q;
	while(Q--){
		ll x,k;
		cin >> x >> k;
		x--;
		ll ans = x+1;
		vector<ll> now,next;
		set<ll> st;
		now.push_back(x);
		st.insert(x);
		rep(i,k){
			rep(j,now.size()){
				ll tmp = now[j];
				rep(t,p[tmp].size()){
					ll node = p[tmp][t];
					if(st.count(node)==0){
						st.insert(node);
						ans += node+1;
						next.push_back(node);
					}
				}
			}
			now = next;
			next.clear();
		}
		cout << ans << endl;
	}
}