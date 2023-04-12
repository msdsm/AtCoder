/*
284E
帰りがけの処理が必要な再帰dfsを非再帰でかく

方針
スタックを3つ用意して
次にみるノード,どのルートできたか,分岐ノードをそれぞれに保存する
*/






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

ll ans;
ll limit = 1000000;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<vector<ll> > p(n);
	rep(i,m){
		ll u,v;
		cin >> u >> v;
		u--;v--;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	vector<bool> visited(n,false);
	stack<ll> s;//みるノード
	stack<ll> r;//帰りがけ用 訪問ノード route
	stack<pll> b;//分岐用branch (node,parent)
	s.push(0);
	while(!s.empty()){
		ll node = s.top();
		s.pop();
		ans++;
		if(ans>=limit){
			break;
		}
		visited[node]=true;
		r.push(node);
		ll tmp = 0;
		rep(i,p[node].size()){
			ll next = p[node][i];
			if(!visited[next]){
				s.push(next);
				tmp++;
				if(tmp>1){//分岐保存
					b.push(pll(next, node));
				}
			}
		}
		if(tmp==0){//葉に到達
			if(b.empty())
				continue;
			pll br = b.top();
			b.pop();
			ll branch = br.snd;
			while(r.top()!=branch){
				visited[r.top()]=false;
				r.pop();
			}
		}
	}
	cout << min(ans,limit) << endl;
}