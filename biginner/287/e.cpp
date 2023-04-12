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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<string> s(n);
	cinf(s,n);
	vector<ll> ans(n);
	vector<vector<ll> > g;
	set<string> st;
	map<string,ll> mp;
	ll depth=0;
	rep(i,n){
		string head = s[i].substr(0,1);
		if(st.count(head)>0){
			g[mp[head]].push_back(i);
		}else{
			vector<ll> tmp;
			tmp.push_back(i);
			g.push_back(tmp);
			mp[head]=g.size()-1;
			st.insert(head);
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,g.size()){
		rep(j,g[i].size()){
			cout << s[g[i][j]] << ' ';
		}cout<<endl;
	}
	cout << "debug end" << endl;
*/
	for(auto itr = g.begin();itr!=g.end();itr++){
/*
		cout << "debug start" << endl;
		cout << (*itr).size() << endl;
		cout << "debug end" << endl;
*/		
		
		if((*itr).size()==1){
			ans[(*itr)[0]]=0;
			g.erase(itr);
			itr--;
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,g.size()){
		rep(j,g[i].size()){
			cout << s[g[i][j]] << ' ';
		}cout<<endl;
	}
	cout << "debug end" << endl;
*/	
	
	while(!g.empty()){
		depth++;
		vector<vector<ll> > next;
		rep(i,g.size()){
			set<char> st2;
			map<char,ll> mp2;
			rep(j,g[i].size()){//この中でs[node][depth]を基準に分割
				if(s[g[i][j]].size()<=depth){
					vector<ll> tmp;
					tmp.push_back(g[i][j]);
					next.push_back(tmp);
					continue;
				}
				char head = s[g[i][j]][depth];
				if(st2.count(head)>0){
					next[mp2[head]].push_back(g[i][j]);
				}else{
					vector<ll> tmp;tmp.push_back(g[i][j]);
					next.push_back(tmp);
					st2.insert(head);
					mp2[head]=next.size()-1;
				}
			}
		}
		/*
		cout << "debug start" << endl;
		rep(i,next.size()){
			rep(j,next[i].size()){
				cout << s[next[i][j]] << ' ';
			}cout<<endl;
		}
		cout << "debug end" << endl;
		*/
		for(auto itr = next.begin();itr!=next.end();itr++){
/*
		cout << "debug start" << endl;
		cout << (*itr).size() << endl;
		cout << "debug end" << endl;
*/		

			if((*itr).size()==1){
				ans[(*itr)[0]]=depth;
				next.erase(itr);
				itr--;
			}
		}
		g = next;
	}
	rep(i,n){
		cout << ans[i] << endl;
	}
}