/*

ABC245F

*/


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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<pll> p(m);
	vector<vector<ll> > path(n);
	vector<vector<ll> > pathr(n);
	rep(i,m){
		ll u,v;
		cin >> u >> v;
		u--;v--;
		p[i].fst=u;
		p[i].snd=v;
		path[u].push_back(v);
		pathr[v].push_back(u);
	}
	vector<bool> ans(n,false);
	vector<bool> visited(n,false);
	vector<bool> leaf(n,true);
	queue<ll> q;
	/*
	rep(i,m){
		leaf[p[i].fst]=false;
	}　
	*/
	rep(i,n){
		if(path[i].size()>0)
			leaf[i]=false;
	}
	rep(i,n){
		if(leaf[i]){
			q.push(i);
			ans[i]=true;
		}
	}
	while(!q.empty()){
		ll tmp = q.front();
		q.pop();
		if(visited[tmp])continue;
		//visited[tmp]=true;
		if(!ans[tmp]){
			rep(i,path[tmp].size()){
				ll node = path[tmp][i];
				if(!ans[node])break;
				if(i==path[tmp].size()-1)
					ans[tmp]=true;
			}
		}
		if(!ans[tmp]){
			visited[tmp]=true;
			continue;
		}
		rep(i,pathr[tmp].size()){
			ll node = pathr[tmp][i];
			if(!ans[node] && !visited[node])
				q.push(node);
		}
		visited[tmp]=true;
	}
	ll cnt = n;
	rep(i,n)if(ans[i])cnt--;
	cout << cnt << endl;
}