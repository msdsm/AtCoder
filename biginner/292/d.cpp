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
		ll u,v;
		cin >> u >> v;
		u--;v--;
		if(u==v){
			p[u].push_back(v);
			continue;
		}
		p[u].push_back(v);
		p[v].push_back(u);
	}
	set<ll> ver;
	rep(i,n)ver.insert(i);
	vector<bool> visited(n);
	while(!ver.empty()){
		ll node = *ver.begin();
/*
		cout << "debug start" << endl;
		cout << node << endl;
		cout << "debug end" << endl;
*/		
		
		//dfs
		stack<ll> s;
		s.push(node);
		ll ncnt=0;
		ll pcnt=0;
		while(!s.empty()){
			ll now = s.top();
			s.pop();
			if(visited[now])continue;
			//辺数える
			rep(i,p[now].size()){
				ll next = p[now][i];
				if(!visited[next]){
					s.push(next);
					pcnt++;
				}
			}
			//ここでtrue
			visited[now]=true;
			ver.erase(now);
			ncnt++;
		}
		if(ncnt!=pcnt){
			//cout << ncnt << endl;
			//cout << pcnt << endl;
			cout << "No" << endl;
			return 0;
		}
		ver.erase(node);
	}
	cout << "Yes" << endl;
}