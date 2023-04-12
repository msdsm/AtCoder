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
	vector<ll> leaf(n);
	vector<bool> isleaf(n);
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
/*
	cout << "debug start depth" << endl;
	rep(i,n){
		cout << "depth" << ' ' << i << endl;
		rep(j,depth[i].size()){
			cout << depth[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/
	ll num = 1;
	for(ll i = n-1;i>=0;i--){
		rep(j,depth[i].size()){
			ll node = depth[i][j];
			if(children[node].size()==0){//leaf
				leaf[node]=1;
				isleaf[node]=true;
			}else{
				rep(k,children[node].size()){
					ll tmp = children[node][k];//child
					leaf[node]+=leaf[tmp];
					isleaf[node]=false;
				}
			}
		}
	}
/*
	cout << "debug start leaf" << endl;
	rep(i,n)cout << leaf[i] << ' ';
	cout << endl;
	rep(i,n)cout << isleaf[i] << ' ';
	cout << endl;
	cout << "debug end" << endl;
*/

	ans[0]=pll(1,leaf[0]);	
	queue<ll> open2;
	vector<bool> visited2(n);
	open2.push(0);
	while(!open2.empty()){
		ll tmp = open2.front();
		open2.pop();
		if(children[tmp].size()==0){
			;
		}else if(children[tmp].size()==1){
			open2.push(children[tmp][0]);
			ans[children[tmp][0]]=ans[tmp];
		}else{
			ans[children[tmp][0]]=pll(ans[tmp].fst,ans[tmp].fst+leaf[children[tmp][0]]-1);
			ans[children[tmp][1]]=pll(ans[children[tmp][0]].snd+1,ans[children[tmp][0]].snd+1+leaf[children[tmp][1]]-1);
			open2.push(children[tmp][0]);
			open2.push(children[tmp][1]);
		}
	}
	rep(i,n){
		cout << ans[i].fst << ' ' << ans[i].snd << endl;
	}
}