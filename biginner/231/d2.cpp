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
	vector<pll> p(m);
	vector<vector<ll> > diff(n);
	rep(i,m){
		ll a,b;
		cin >> a >> b;
		p[i].fst = --a;
		p[i].snd = --b;
		diff[a].push_back(b);
		diff[b].push_back(a);
	}
/*
	cout << "debug start" << endl;
	rep(i,n){
		rep(j,diff[i].size()){
			cout << diff[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/	
	
	stack<pll> open;
	vector<bool> visited(n);
	set<ll> remain;
	rep(i,n)remain.insert(i);
	while(remain.size()!=0){
		auto itr = remain.begin();
/*
		cout << "debug start" << endl;
		cout << *itr << endl;
		cout << visited[*itr] << endl;
		cout << "debug end" << endl;
*/		
		
		remain.erase(itr);
		if(visited[*itr]){
			cout << "No" << endl;
			return 0;
		}
		open.push(pll(*itr,-1));
		while(!open.empty()){
			pll tmp = open.top();
			open.pop();
/*
			cout << "debug start open" << endl;
			cout << tmp.fst << endl;
			cout << visited[tmp.fst] << endl;
			cout << "debug end" << endl;
*/			
			
			if(visited[tmp.fst]){
				cout << "No" << endl;
				return 0;
			}
			visited[tmp.fst]=true;
			remain.erase(tmp.fst);
/*
			cout << "debug start diff" << endl;
			cout << tmp.snd << endl;
			cout << diff[tmp.fst].size() << endl;
			cout << "debug end" << endl;
*/			
			
			if(diff[tmp.fst].size()>2){
				cout << "No" << endl;
				return 0;
			}
			rep(i,diff[tmp.fst].size()){
				if(diff[tmp.fst][i]!=tmp.snd)
					open.push(pll(diff[tmp.fst][i],tmp.fst));
			}
		}
	}
	cout << "Yes" << endl;
}