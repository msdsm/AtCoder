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
	ll n;
	cin >> n;
	vector<pll> p(n-1);
	vector<pll> ans(n);
	rep(i,n){
		ans[i].fst=-1;
		ans[i].snd=-1;
	}
	vector<vector<ll> > depth(n);
	vector<ll> d(n);
	vector<vector<ll> > path(n);
	vector<vector<ll> > children(n);
	vector<bool> visited(n);
	rep(i,n-1){
		ll u,v;
		cin >> u >> v;
		u--;v--;
		p[i].fst=u;
		p[i].snd=v;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	queue<pll> open;
	open.push(pll(0,0));
	visited[0]=true;
	depth[0].push_back(0);
	d[0]=0;
	while(!open.empty()){
		pll tmp = open.front();
		open.pop();
		rep(i,path[tmp.fst].size()){
			if(!visited[path[tmp.fst][i]]){
				open.push(pll(path[tmp.fst][i],tmp.snd+1));
				visited[path[tmp.fst][i]]=true;
				depth[tmp.snd+1].push_back(path[tmp.fst][i]);
				d[path[tmp.fst][i]]=tmp.snd+1;
			}
		}
	}
	rep(i,n){
		rep(j,path[i].size()){
			if(d[i]<d[path[i][j]])
				children[i].push_back(path[i][j]);
		}
	}

	cout << "debug start depth" << endl;
	rep(i,n){
		cout << "depth" << ' ' << i << endl;
		rep(j,depth[i].size()){
			cout << depth[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;

	ll num = 1;
	for(ll i = n-1;i>=0;i--){
		rep(j,depth[i].size()){
			ll node = depth[i][j];
			if(children[node].size()==0){//leaf
				ans[node].fst=num;
				ans[node].snd=num;
				num++;
			}else{
				rep(k,children[node].size()){
					ll tmp = children[node][k];//child
					if(ans[node].fst==-1){
						ans[node].fst=ans[tmp].fst;
					}else{
						ans[node].fst=min(ans[node].fst,ans[tmp].fst);
					}
					if(ans[node].snd==-1){
						ans[node].snd=ans[tmp].snd;
					}else{
						ans[node].snd=max(ans[node].snd,ans[tmp].snd);
					}
				}
			}
		}
	}
	rep(i,n){
		cout << ans[i].fst << ' ' << ans[i].snd << endl;
	}
}