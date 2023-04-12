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

using P = pair<ll, vector<ll> >;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,x,y;
	cin >> n >> x >> y;
	x--;
	y--;
	vector<vector<ll> > path(n);
	rep(i,n-1){
		ll u,v;
		cin >> u >> v;
		u--;
		v--;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	stack<P> q;
	q.push(P(x,vector<ll>(1,x+1)));
	vector<bool> visited(n);
	visited[x]=true;
	while(!q.empty()){
		P tmp = q.top();
		q.pop();
		ll node = tmp.fst;
		vector<ll> v = tmp.snd;
		if(node==y){
			rep(i,v.size()){
				cout << v[i] << ' ';
			}cout<<endl;
			break;
		}
		rep(i,path[node].size()){
			ll next = path[node][i];
			if(!visited[next]){
				visited[next]=true;
				v.push_back(next+1);
				q.push(P(next, v));
				v.pop_back();
			}
		}
	}
}