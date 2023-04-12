#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<pii> p(m);
	vector<vector<int> > g(n);
	rep(i,m){
		cin >> p[i].first >> p[i].second;
	}
	rep(i,m){
		g[p[i].first-1].push_back(p[i].second-1);
	}
	rep(i,n){
		set<int> closed;
		queue<int> open;
		rep(j,g[i].size()){
			open.push(g[i][j]);
		}
		while(!open.empty()){
			int tmp = open.front();
			open.pop();
			if(closed.count(tmp)==0 && tmp!=i){
				closed.insert(tmp);
				rep(j,g[tmp].size()){
					if(closed.count(g[tmp][j])==0)
						open.push(g[tmp][j]);
				}
			}
		}
		cnt += closed.size();
/*
		cout << "debug start" << endl;
		for(auto itr = closed.begin();itr!=closed.end();itr++){
			cout << '(' << i+1 << ',' << (*itr)+1 << ')' << endl;
		}
		cout << "debug end" << endl;
*/		
		
	}
	cout << cnt + n << endl;
}