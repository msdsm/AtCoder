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
	vector<vector<ll> > p(n);//有向グラフ
	vector<ll> indeg(n);//indegree:入次数
	rep(i,m){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		p[x].push_back(y);
		indeg[y]++;
	}
	ll s=-1;//始点
	rep(i,n){
		if(indeg[i]==0)
			s = i;
	}
	if(s==-1){//始点がない
		cout << "No" << endl;
		return 0;
	}
	queue<ll> q;//入次数0になったノード
	q.push(s);
	vector<ll> ans;
	while(!q.empty()){
		ll now = q.front();
		q.pop();
		ans.push_back(now);
		rep(i,p[now].size()){
			ll next = p[now][i];
			indeg[next]--;//辺削除
			if(indeg[next]==0){
				q.push(next);
			}
		}
	}
	if(ans.size()!=n){//トポロジカルソートできない,DAGでない,閉路存在
		cout << "No" << endl;
		return 0;
	}

	//ここから解が一意に定まるか確認
	//ハミルトン路が存在するかどうか
	vector<set<ll> > path(n);
	rep(i,n){
		rep(j,p[i].size()){
			path[i].insert(p[i][j]);
		}
	}

	rep2(1,i,n){
		ll now = ans[i-1];
		ll next = ans[i];
		if(path[now].count(next))
			continue;
		else{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	vector<ll> val(n);
	rep(i,n){
		val[ans[i]] = i+1;
	}
	rep(i,n)cout<<val[i]<<' ';
	cout<<endl;
}