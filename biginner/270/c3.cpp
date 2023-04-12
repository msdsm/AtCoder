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
	ll n,x,y;
	cin >> n >> x >> y;
	x--;
	y--;
	vector<vector<ll> > path(n);
	vector<ll> parent(n);
	vector<vector<ll> > children(n);
	rep(i,n-1){
		ll u,v;
		cin >> u >> v;
		u--;
		v--;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	parent[x]=-1;//根
	queue<pll> q;
	vector<bool> visited(n);
	visited[x]=true;
	q.push(pll(x,-1));
	while(!q.empty()){
		pll tmp = q.front();
		q.pop();
		ll node = tmp.fst;
		ll pre = tmp.snd;
		parent[node]=pre;
		rep(i,path[node].size()){
			ll next = path[node][i];
			if(!visited[next]){
				visited[next]=true;
				q.push(pll(next, node));
				children[node].push_back(next);
			}
		}
	}
	vector<ll> ans;
	ll node = y;
	//ans.push_back(node+1);
	while(parent[node]!=-1){
		ans.push_back(node+1);
		node = parent[node];
	}
	ans.push_back(x+1);
	reverse(ans.begin(), ans.end());
	rep(i,ans.size()){
		cout << ans[i] << ' ';
	}cout<<endl;
}