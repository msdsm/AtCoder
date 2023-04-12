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
	vector<ll> a(n-1),b(n-1);
	vector<pll> ans;
	rep(i,n-1)cin>>a[i]>>b[i];
	rep(i,n-1){
		a[i]--;
		b[i]--;
	}
	vector<vector<ll> > dist(n);
	rep(i,n)dist[i].push_back(-1);
	rep(i,n-1){
		if(dist[a[i]][0]!=-1)
			dist[a[i]].push_back(b[i]);
		else
			dist[a[i]][0]=b[i];

		if(dist[b[i]][0]!=-1)
			dist[b[i]].push_back(a[i]);
		else
			dist[b[i]][0]=a[i];
	}
	rep(i,n){
		sort(dist[i].begin(),dist[i].end(),greater<ll>());
	}
/*
	cout << "debug start" << endl;
	rep(i,n){
		rep(j,dist[i].size()){
			cout << dist[i][j]+1 << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/
	stack<pll> open;
	set<ll> closed;
	open.push(pll(0,-1));
	while(!open.empty()){
		pll tmp;
		tmp = open.top();
		open.pop();
		closed.insert(tmp.fst);
		ans.push_back(tmp);
		rep(i,dist[tmp.fst].size()){
			if(closed.count(dist[tmp.fst][i])>0){
				continue;
			}else{
				open.push(pll(dist[tmp.fst][i],tmp.fst));
			}
		}
	}

/*	cout << "debug start" << endl;
	rep(i,ans.size()){
		cout << ans[i].fst+1 << '(' << ans[i].snd+1 << ')' << ' ';
	}
	cout << "debug end" << endl;
*/	

	ll pre = -1;
	rep(i,ans.size()){
		//cout << ans[i].fst+1 << '(' << ans[i].snd+1 << ')' << ' ';
		if(ans[i].snd==pre){
			cout << ans[i].fst+1 << ' ';
		}else{
			ll j = i-2;
			while(true){
				cout << ans[j].fst+1 << ' ';
				if(ans[j].fst==ans[i].snd)
					break;
				j--;
			}
			cout << ans[i].fst+1 << ' ';
		}
		pre=ans[i].fst;
	}
	//cout << "あいうえお" << endl;
	ll i = ans.size()-1;
	while(true){
		cout << ans[i].snd+1 << ' ';
		if(ans[i].snd+1==1)
			break;
		i--;
	}
	cout << endl;
}