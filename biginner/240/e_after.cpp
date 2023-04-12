//ABC240E

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
	vector<vector<ll> > path(n);
	rep(i,n-1){
		ll u,v;
		cin >> u >> v;
		u--;
		v--;
		p[i].fst = u;
		p[i].snd = v;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	stack<ll> open;
	vector<bool> visited(n);
	vector<ll> closed;
	open.push(0);
	visited[0]=true;
	while(!open.empty()){
		ll tmp = open.top();
		open.pop();
		closed.push_back(tmp);
		rep(i,path[tmp].size()){
			ll node = path[tmp][i];
			if(!visited[node]){
				open.push(node);
				visited[node]=true;
			}
		}
	}
	reverse(closed.begin(),closed.end());
	vector<bool> isleaf(n);
	isleaf[0]=false;
	rep2(1,i,n){
		if(path[i].size()==1)
			isleaf[i]=true;
		else
			isleaf[i]=false;
	}
	vector<vector<ll> > children(n);
	stack<ll> open2;
	open2.push(0);
	children[0] = path[0];
	vector<bool> visited2(n);
	while(!open2.empty()){
		ll tmp = open2.top();
		open2.pop();
		rep(i,path[tmp].size()){
			ll node = path[tmp][i];
			if(!visited2[node]){
				open2.push(node);
				children[tmp].push_back(node);
			}
		}
		visited2[tmp]=true;
	}
	ll num = 1;
	vector<pll> ans(n);
	rep(i,n){
		ll tmp = closed[i];
		if(isleaf[tmp]){
			ans[tmp].fst = num;
			ans[tmp].snd = num;
			num++;
		}else{
			ll l = numeric_limits<ll>::max();
			ll r = 0;
			rep(j,children[tmp].size()){
				ll node = children[tmp][j];
				l = min(l,ans[node].fst);
				r = max(r,ans[node].snd);
			}
			ans[tmp].fst=l;
			ans[tmp].snd=r;
		}
	}
/*
	cout << "debug start path" << endl;
	rep(i,path.size()){
		rep(j,path[i].size()){
			cout << path[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
	
	cout << "debug start isleaf" << endl;
	rep(i,n)cout << isleaf[i] << endl;
	cout << "debug end" << endl;

	cout << "debug start children" << endl;
	rep(i,children.size()){
		rep(j,children[i].size()){
			cout << children[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/
	rep(i,n){
		cout << ans[i].fst << ' ' << ans[i].snd << endl;
	}
}