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
	ll n,m;
	cin >> n >> m;
	vector<vector<ll> > p(n);//edge
	rep(i,m){
		ll u, v;
		cin >> u >> v;
		u--;v--;
		p[u].push_back(v);
		p[v].push_back(u);
	} 
	ll k;
	cin >> k;
	vector<pll> c(k);
	pcin(c,k); 
	rep(i,k)c[i].fst--;
	vector<vector<ll> > v(k);
	set<ll> ng;//ng
	rep(i,k){
		ll depth = c[i].snd;
		ll start = c[i].fst;
		queue<pll> q;//vertex, depth
		vector<bool> visited(n, false);
		q.push(pll(start, 0));
		visited[start]=true;
		while(!q.empty()){
			pll tmp = q.front();
			q.pop();
			ll now = tmp.fst;
			ll d = tmp.snd;
			if(d==depth){
				v[i].push_back(now);
				continue;
			}
			ng.insert(now);
			rep(j,p[now].size()){
				ll next = p[now][j];
				if(!visited[next]){
					q.push(pll(next, d+1));
					visited[next]=true;
				}
			}
		}
	}
	set<ll> idx;
	rep(i,k){
		bool flag = false;
		rep(j,v[i].size()){
			if(ng.count(v[i][j])==0){
				flag = true;
				idx.insert(v[i][j]);//黒
				break;
			}
		}
		if(!flag){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	vector<ll> ans(n, 0);
	for(auto itr=idx.begin();itr!=idx.end();itr++){
		ans[*itr] = 1;
	}
	if(idx.size()==0){
		ans[0]=1;
	}
	rep(i,n){
		if(i!=n-1)
			cout << ans[i];
		else
			cout << ans[i] << endl;
	}
}