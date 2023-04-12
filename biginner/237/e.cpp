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
	vector<ll> h(n);
	cinf(h,n);
	vector<pll> p(m);
	pcin(p,m);
	rep(i,m){
		p[i].fst--;
		p[i].snd--;
	}
	vector<vector<ll> > path(n);
	rep(i,m){
		path[p[i].fst].push_back(p[i].snd);
		path[p[i].snd].push_back(p[i].fst);
	}
/*
	cout << "debug start" << endl;
	rep(i,n){
		rep(j,path[i].size()){
			cout << path[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/
	vector<bool> visited(n);//値存在
	queue<ll> open;
	open.push(0);
	visited[0]=true;
	vector<ll> ans(n);
	ans[0]=0;
	while(!open.empty()){
		ll tmp = open.front();
		open.pop();
		rep(j,path[tmp].size()){
			if(!visited[path[tmp][j]]){
				visited[path[tmp][j]]=true;
				open.push(path[tmp][j]);
				if(h[path[tmp][j]]<h[tmp])
					ans[path[tmp][j]] = ans[tmp]+h[tmp]-h[path[tmp][j]];
				else if(h[path[tmp][j]]>h[tmp])
					ans[path[tmp][j]] = ans[tmp]+2*(h[tmp]-h[path[tmp][j]]);
				else
					ans[path[tmp][j]] = ans[tmp];
			}else{
				ll diff,tmp2,tmp3; 
				if(h[path[tmp][j]]<h[tmp])
					diff = h[tmp]-h[path[tmp][j]];
				else if(h[path[tmp][j]]>h[tmp])
					diff = 2*(h[tmp]-h[path[tmp][j]]);
				else
					diff = 0;
				tmp2 = max(ans[path[tmp][j]],ans[tmp]+diff);
				if(h[path[tmp][j]]>h[tmp])
					diff = h[path[tmp][j]]-h[tmp];
				else if(h[path[tmp][j]]<h[tmp])
					diff = 2*(h[path[tmp][j]]-h[tmp]);
				else
					diff = 0;
				tmp3 = max(ans[tmp],ans[path[tmp][j]]+diff);
				ans[path[tmp][j]] = tmp2;
				ans[tmp] = tmp3;
			}
		}
	}
	rep(t,500){
		rep(i,m){
			ll u = p[i].fst;
			ll v = p[i].snd;
			ll diff,tmp2,tmp3;
			if(h[u]<h[v])
				diff = h[v]-h[u];
			else if(h[u]>h[v])
				diff = 2*(h[v]-h[u]);
			else
				diff = 0;
			tmp2 = max(ans[u],ans[v]+diff);
			if(h[u]>h[v])
				diff = h[u]-h[v];
			else if(h[u]<h[v])
				diff = 2*(h[u]-h[v]);
			else
				diff = 0;
			tmp3 = max(ans[v],ans[u]+diff);
			ans[u] = tmp2;
			ans[v] = tmp3;
		}
	}
	ll max = ans[0];
	rep(i,n){
		if(ans[i]>max)
			max=ans[i];
	}
	cout << max << endl;
}