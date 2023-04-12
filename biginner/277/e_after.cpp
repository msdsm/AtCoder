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

using P = pair<ll, pll>;//score,node,state

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m,k;
	cin >> n >> m >> k;
	vector<vector<vector<ll> > > path(2);
	path[0].resize(n);
	path[1].resize(n);
	rep(i,m){
		ll u,v,a;
		cin >> u >> v >> a;
		u--;
		v--;
		path[a][u].push_back(v);
		path[a][v].push_back(u);
	}
	vector<ll> s(k);
	cinf(s,k);
	rep(i,k)s[i]--;
	vector<bool> swi(n,false);
	rep(i,k)swi[s[i]]=true;

	priority_queue<P, vector<P>, greater<P> > pq;

	vector<vector<bool> > visited(2);
	visited[0].resize(n,false);visited[1].resize(n,false);

	vector<vector<ll> > score(2);
	ll inf = numeric_limits<ll>::max();
	score[0].resize(n, inf); score[1].resize(n,inf);

	P start = P(0, pll(ll(0),ll(1)));//cost0,index0,通れる道1
	pq.push(start);
	while(!pq.empty()){
		P tmp = pq.top();
		pq.pop();
		ll cost = tmp.fst;
		ll now = tmp.snd.fst;
		ll state = tmp.snd.snd;
		if(visited[state][now])
			continue;
		visited[state][now]=true;
		rep(i,path[state][now].size()){
			ll next = path[state][now][i];
			if(!visited[state][next]){
				pq.push(P(cost+1, pll(next, state)));
				score[state][next]=min(cost+1,score[state][next]);
			}
		}
		if(swi[now]){
			rep(i,path[1-state][now].size()){
				ll next = path[1-state][now][i];
				if(!visited[1-state][next]){
					pq.push(P(cost+1, pll(next, 1-state)));
					score[1-state][next]=min(cost+1,score[1-state][next]);
				}
			}
		}
	}
	if(!visited[0][n-1]&&!visited[1][n-1])
		cout << -1 << endl;
	else
		cout << min(score[0][n-1], score[1][n-1]) << endl;
}