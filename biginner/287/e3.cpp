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
		/*
		cout << "debug start" << endl;
		rep(i,g.size()){
			rep(j,g[i].size()){
				cout << s[g[i][j]] << ' ';
			}cout<<endl;
		}
		cout << "debug end" << endl;
		*/
		depth++;
		ll num = g.size();
		rep(i,num){
			vector<vector<ll> > next(26);
			rep(j,g[0].size()){//この中でs[node][depth]を基準に分割
				ll node = g[0][j];
				if(s[node].size()<=depth){
					ans[node]=depth;
					continue;
				}
				char head = s[node][depth];
				next[head-'a'].push_back(node);
			}
			rep(t,26){
				if(next[t].size()==0){
					continue;
				}else if(next[t].size()==1){
					ans[next[t][0]]=depth;
				}else{
					g.push_back(next[t]);
				}
			}
			g.erase(g.begin());
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
	}
	rep(i,n){
		cout << ans[i] << endl;
	}
}