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
	vector<string> s(n),t(n);
	rep(i,n){
		cin >> s[i] >> t[i];
	}
	map<string, ll> mp;
	rep(i,n)mp[s[i]]=i;
	set<string> st;
	rep(i,n){
		st.insert(s[i]);
	}
	vector<ll> indeg(n, 0);
	queue<ll> q;
	vector<ll> ans;
	vector<vector<ll> > path(n);
	rep(i,n){
		if(st.count(t[i])>0){
			//cout << i << endl;
			path[i].push_back(mp[t[i]]);
			indeg[mp[t[i]]]++;
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,n){
		rep(j,path[i].size()){
			cout << i << ' ' << j << ' ';
			cout << path[i][j] << endl;
		}
	}
	cout<<endl;
	
	rep(i,n){
		cout << indeg[i] << endl;
	}
	cout << "debug end" << endl;*/
	
	
	rep(i,n){
		if(indeg[i]==0)
			q.push(i);
	}
	while(!q.empty()){
		ll tmp = q.front();
		q.pop();
		ans.push_back(tmp);
		rep(i,path[tmp].size()){
			ll next = path[tmp][i];
			indeg[next]--;
			if(indeg[next]==0){
				q.push(next);
			}
		}
	}
	if(ans.size()==n)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}