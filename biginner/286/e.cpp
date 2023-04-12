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

using P = pair<pll,ll> ;

ll n;
vector<vector<ll> > p(310);
vector<ll> a(310);
vector<ll> ans;
ll cnt;
vector<bool> reached(310);

void dfs(ll now,ll g,ll d,ll val){//node,goal,depth,value
	reached[now]=true;
	val += a[now];
	rep(i,p[now].size()){
		ll next = p[now][i];
		if(!reached[next]){
			if(d+1==cnt){
				if(next==g)
					ans.push_back(val+a[next]);
			}else{
				dfs(next, g, d+1, val);
			}
		}
	}
	reached[now]=false;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	cin >> n;
	cinf(a,n);
	vector<string> s(n);
	cinf(s,n);
	//vector<vector<ll> > p(n);
	rep(i,n){
		rep(j,n){
			if(s[i][j]=='Y')
				p[i].push_back(j);
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,n){
		rep(j,p[i].size()){
			cout << p[i][j] << ' ';
		}cout<<endl;
	}
	cout << "debug end" << endl;
*/	
	
	ll q;
	cin >> q;
	while(q--){
		ll u,v;
		cin >> u >> v;
		u--;v--;
		queue<pll> q;
		cnt=0;
		q.push(pll(u,0));
		vector<bool> visited(n,false);
		visited[u]=true;
		bool flag = false;
		while(!q.empty()){
			pll tmp = q.front();
			q.pop();
			ll now = tmp.fst;
			ll c = tmp.snd;
			rep(i,p[now].size()){
				ll next = p[now][i];
				if(next==v){
					cnt = c+1;
					flag = true;
					break;
				}
				if(!visited[next]){
					visited[next]=true;
					q.push(pll(next,c+1));
				}
			}
			if(flag)
				break;
		}
		if(cnt==0){
			cout << "Impossible" << endl;
			continue;
		}
		rep(i,n){
			reached[i]=false;
		}
		ans.resize(0);
		dfs(u,v,0,0);
		ll max = 0;
		rep(i,ans.size()){
			if(max<ans[i])
				max = ans[i];
		}
		cout << cnt << ' ' << max << endl;
	}
}