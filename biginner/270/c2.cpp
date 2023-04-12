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
vector<ll> ans;

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
	stack<ll> q;
	q.push(x);
	vector<bool> visited(n);
	visited[x]=true;
	cout << x+1 << ' ';
	while(!q.empty()){
		ll node = q.top();
		q.pop();
		bool flag = false;
		rep(i,path[node].size()){
			ll next = path[node][i];
			if(next==y){
				rep(i,ans.size()){
					cout << ans[i] << ' ';
				}
				cout << y+1 << endl;
				break;
			}
			if(!visited[next]){
				flag = true;
				visited[next]=true;
				q.push(next);
				ans.push_back(next+1);
			}
		}
		if(!flag){
			ans.clear();
		}
	}
}