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

ll f(ll x,ll y){
	if(x>=y)
		return 0;
	else
		return y-x;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<ll> h(n);
	cinf(h,n);
	vector<pll> p(m);
	rep(i,m){
		ll u,v;
		cin >> u >> v;
		u--;
		v--;
		p[i].fst = u;
		p[i].snd = v;
	}
	vector<vector<pll> > path(n);//ノードiに繋がるノード及び重み
	rep(i,m){
		path[p[i].fst].push_back(pll(p[i].snd,f(h[p[i].fst],h[p[i].snd])));
		path[p[i].snd].push_back(pll(p[i].fst,f(h[p[i].snd],h[p[i].fst])));
	}
/*
	cout << "debug start" << endl;
	rep(i,m){
		rep(j,path[i].size()){
			cout << path[i][j].fst << ' ' << path[i][j].snd << endl;
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/	
	
	priority_queue<pll,vector<pll>,greater<pll> > q;
	vector<bool> closed(n);
	vector<ll> cost(n,-1);
	cost[0]=0;
//	rep(i,n)cout << cost[i] << endl;
	q.push(pll(0,0));//cost,node
	ll max = 0;
	while(!q.empty()){
		pll tmp = q.top();
		ll v = tmp.snd;
		ll c = tmp.fst;
		q.pop();
		if(!closed[v]){
			rep(i,path[v].size()){
				pll tmp2 = path[v][i];
				if(!closed[tmp2.fst]){
					if(cost[tmp2.fst]==-1){
						cost[tmp2.fst] = c+tmp2.snd;
						q.push(pll(cost[tmp2.fst],tmp2.fst));
					}else{
						cost[tmp2.fst] = min(cost[tmp2.fst],c+tmp2.snd);
						q.push(pll(cost[tmp2.fst],tmp2.fst));
					}
				}else{
					continue;
				}
			}
			closed[v]=true;
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,n)cout << cost[i] << endl;
	cout << "debug end" << endl;
*/	
	
	rep(i,n){
		if(max<h[0]-h[i]-cost[i])
			max = h[0]-h[i]-cost[i];
	}
	cout << max << endl;
}