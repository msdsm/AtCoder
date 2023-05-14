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
ll inf = numeric_limits<ll>::max();
using P = pair<pll, ll>;

ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};

bool f(ll x, ll left, ll right){//x in [left, right)
	if(left <= x  && x < right)
		return true;
	else
		return false;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll h,w,t;
	cin >> h >> w >> t;
	vector<vector<char> > a(h);
	rep(i,h)a[i].resize(w);
	rep(i,h)rep(j,w)cin>>a[i][j];

	pll s,g;
	vector<pll> o;
	rep(i,h){
		rep(j,w){
			if(a[i][j]=='o')
				o.push_back(pll(i,j));
			if(a[i][j]=='S')
				s = pll(i,j);
			if(a[i][j]=='G')
				g = pll(i,j);
		}
	}
	vector<pll> v;//スタート、おやつ、ゴール
	v.push_back(s);
	rep(i,o.size())v.push_back(o[i]);
	v.push_back(g);

	//各地点間の距離
	vector<vector<ll> > d(v.size());
	rep(i,v.size())d[i].resize(v.size(),inf);
	rep(i,v.size()){
		pll start = v[i];
		rep2(i+1,j,v.size()){
			pll goal = v[j];
			queue<P> que;//座標、深さ
			vector<vector<bool> > visited(h);
			rep(tmp,h)visited[tmp].resize(w,false);
			que.push(P(start, 0));
			visited[start.fst][start.snd] = true;
			while(!que.empty()){
				P tmp = que.front();
				que.pop();
				pll now = tmp.fst;
				ll depth = tmp.snd;
				rep(idx, 4){
					pll next = pll(now.fst + dx[idx], now.snd + dy[idx]);
					if(next==goal){
						d[i][j] = depth+1;
						break;
					}
					if(f(next.fst, 0, h)&&f(next.snd, 0, w)&&a[next.fst][next.snd]!='#'&&!visited[next.fst][next.snd]){
						que.push(P(next, depth+1));
						visited[next.fst][next.snd]=true;
					}
				}
			}
		}
	}
	if(d[0][v.size()-1]>t){
		cout << -1 << endl;
		return 0;
	}
	ll num = v.size();
	vector<vector<ll> > dp(1<<num);//dp_ij : 集合iを通りjにいる時の最短経路
	rep(i,1<<num)dp[i].resize(num, inf);
	dp[1<<0][0] = 0;
	rep(i, 1<<num){
		rep(j,num){
			if(dp[i][j]==inf)
				continue;
			rep(k,num){
				if(j==k)
					continue;
				if(d[min(j,k)][max(j,k)]!=inf){
					dp[(1<<k)|i][k] = min(dp[(1<<k)|i][k],dp[i][j]+d[min(j,k)][max(j,k)]);
				}
			}
		}
	}
	ll ans = 0;
	rep(i,1<<num){
		if(dp[i][v.size()-1]<=t && (i&(1<<0))==1 && (i&(1<<v.size()-1))==1){
			if(ans<__builtin_popcount(i))
				ans = __builtin_popcount(i)-2;
		}
	}
	cout << ans << endl;
}