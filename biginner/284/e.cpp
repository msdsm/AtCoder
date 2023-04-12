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

ll ans;

using P = pair<ll, set<ll> >;//今,通った集合

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<vector<ll> > path(n);
	rep(i,m){
		ll u,v;
		cin >> u >> v;
		u--;
		v--;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	queue<P> s;
	set<ll> st;
	st.insert(0);
	s.push(P(0, st));
	ans++;
	while(!s.empty()){
		P tmp = s.front();
		s.pop();
		ll node = tmp.fst;
		set<ll> visited = tmp.snd;
		rep(i,path[node].size()){
			ll next = path[node][i];
			if(visited.count(next)==0){
				visited.insert(next);
				s.push(P(next, visited));
				ans++;
				if(ans==1000000){
					cout << 1000000 << endl;
					return 0;
				}
				visited.erase(next);
			}
		}
	}
	cout << ans << endl;
}