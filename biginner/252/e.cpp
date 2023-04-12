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
	vector<pair<ll,pll> > e(m);
	vector<vector<pll> > path(n); //cost, index of node
	map<pair<ll,pll>,ll> index;
	vector<ll> ans;
	rep(i,m){
		ll a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		e[i] = pair<ll,pll>(c,pll(a,b));
		path[a].push_back(pll(c,b));
		path[b].push_back(pll(c,a));
		index[e[i]] = i+1;
	}
	rep(i,n){
		sort(path[i].begin(),path[i].end());
	}
	priority_queue<pair<ll,pll>,vector<pair<ll,pll> >,greater<pair<ll,pll> > > q;//cost,index of edge
	vector<bool> visited(n,false);
	visited[0]=true;
	vector<ll> cost(n);
	cost[0]=0;
	rep(i,path[0].size()){
		if(!visited[path[0][i].snd]){
			ll node = path[0][i].snd;
			q.push(
				pair<ll,pll>(cost[0]+path[0][i].fst,
					pll(
						node,
						index[pair<ll,pll>(path[0][i].fst,pll(min(ll(0),node),max(ll(0),node)))]
						)
					)
				);
		}
	}
	while(!q.empty()){
		pair<ll,pll> p = q.top();
		q.pop();
		ll now = p.snd.fst;
		if(!visited[now]){
			visited[now]=true;
			ans.push_back(p.snd.snd);
			cost[now] = p.fst;
			rep(i,path[now].size()){
				ll next = path[now][i].snd;
				ll c = path[now][i].fst;
				if(!visited[next]){
					q.push(
						pair<ll,pll>(cost[now]+c, 
							pll(
								next,
								index[pair<ll,pll>(c,pll(min(now,next),max(now,next)))]
								)
							)
						);
				}
			}
		}
	}
	rep(i,ans.size()){
		cout << ans[i] << ' ';
	}
	cout << endl;
}