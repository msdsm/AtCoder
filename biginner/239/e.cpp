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
	ll n,q;
	cin >> n >> q;
	vector<ll> x(n);
	cinf(x,n);
	vector<pll> p(n-1);
	vector<vector<ll> > ans(n);
	vector<vector<ll> > depth(n);
	vector<ll> d(n);
	vector<vector<ll> > path(n);
	vector<vector<ll> > children(n);
	vector<bool> visited(n);
	rep(i,n-1){
		ll a,b;
		cin >> a >> b;
		a--;
		b--;
		p[i].fst=a;
		p[i].snd=b;
		path[a].push_back(b);
		path[b].push_back(a);
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
	cout << "debug start" << endl;
	rep(i,n){
		cout << i << ':' << endl;
		rep(j,children[i].size()){
			cout << children[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/
	
/*	
	cout << "debug start path" << endl;
	rep(i,n){
		cout << i << ':' << endl;
		rep(j,path[i].size()){
			cout << path[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/
/*
	cout << "debug start d" << endl;
	rep(i,n)cout << d[i] << ' ';
	cout << endl;
	cout << "debug end" << endl;
*/	
	
	
	for(ll i = n-1;i>=0;i--){
		rep(j,depth[i].size()){
			ll node = depth[i][j];
			rep(k,children[node].size()){
				ll tmp = children[node][k];
				ll cnt=0;
				ll ii = 0;
				while(ii<ans[tmp].size()&&cnt<20){
					ans[node].push_back(ans[tmp][ii]);
					cnt++;
					ii++;
				}
			}

			
			
			ans[node].push_back(x[node]);
			if(ans[node].size()>=2){
				sort(ans[node].begin(),ans[node].end());
				reverse(ans[node].begin(),ans[node].end());
			}
			
			
			if(ans[node].size()>20){
				while(ans[node].size()>20)
					ans[node].pop_back();
			}
			
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,n){
		cout << "depth" << ' ' << i << endl;
		rep(j,depth[i].size()){
			cout << depth[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
	
*/
/*
	cout << "debug start ans" << endl;
	rep(i,n){
		cout << i << ':' << endl;
		rep(j,ans[i].size())cout << ans[i][j] << ' ';
		cout << endl;
	}
	cout << "debug end" << endl;
	
	*/
	
	rep(iii,q){
		ll v,k;
		cin >> v >> k;
		cout << ans[v-1][k-1] << endl;
	}
}