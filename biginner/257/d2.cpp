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

using P = pair<pll,ll>;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<P> p(n);
	rep(i,n){
		ll x,y,po;
		cin >> x >> y >> po;
		p[i].fst.fst = x;
		p[i].fst.snd = y;
		p[i].snd = po;
	}
	vector<vector<ll> > path(n);
	rep(i,n)path[i].resize(n);
	rep(i,n){
		rep(j,n){
			if(i==j)
				path[i][j]=0;
			else	
				path[i][j]=ceil((abs(p[i].fst.fst-p[j].fst.fst)+abs(p[i].fst.snd-p[j].fst.snd))/p[i].snd);
		}
	}

	vector<vector<ll> > d(n);
	rep(i,n)d[i].resize(n);
	rep(i,n){
		rep(j,n){
			d[i][j]=path[i][j];
		}
	}
	rep(ttt,n){
		ll start = ttt;
		priority_queue<pll> pq;//cost,node
		pq.push(pll(start,ll(0)));
		vector<ll> dis(n);
		rep(i,n)dis[i]=path[start][i];
		vector<bool> visited(n);
		while(!pq.empty()){
			pll tmp =pq.top();
			ll now = tmp.snd;
			ll cost = tmp.fst;
			pq.pop();
			if(visited[now])continue;
			visited[now]=true;
			rep(i,n){
				if(!visited[i]){
					if(dis[i]>max(cost,path[now][i])){
						dis[i]=max(cost,path[now][i]);
						pq.push(pll(dis[i],i));
					}
				}
			}
		}
		rep(i,n){
			d[start][i]=dis[i];
		}
	}
	rep(ttt,n){
		ll start = ttt;
		priority_queue<pll> pq;//cost,node
		pq.push(pll(start,ll(0)));
		vector<ll> dis(n);
		rep(i,n)dis[i]=d[start][i];
		vector<bool> visited(n);
		while(!pq.empty()){
			pll tmp =pq.top();
			ll now = tmp.snd;
			ll cost = tmp.fst;
			pq.pop();
			if(visited[now])continue;
			visited[now]=true;
			rep(i,n){
				if(!visited[i]){
					if(dis[i]>max(cost,d[now][i])){
						dis[i]=max(cost,d[now][i]);
						pq.push(pll(dis[i],i));
					}
				}
			}
		}
		rep(i,n){
			d[start][i]=min(d[start][i],dis[i]);
		}
	}
	
/*	
	cout << "debug start path" << endl;
	rep(i,n){
		rep(j,n){
			cout << path[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
	cout << endl;
	cout << "debug start d" << endl;
	rep(i,n){
		rep(j,n){
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/	

	ll ans = numeric_limits<ll>::max();
	rep(i,n){
		ll tmp = d[i][0];
		rep(j,n){
			if(tmp<d[i][j])
				tmp=d[i][j];
		}
		if(ans>tmp)
			ans = tmp;
	}
	cout << ans << endl;
}