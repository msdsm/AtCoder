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
	ll q;
	cin >> q;
	vector<vector<ll> > note(500010);
	map<ll,ll> mp;
	vector<ll> a;
	ll cnt = 0;
	while(q--){
		string s;
		cin >> s;
		if(s=="ADD"){
			ll x;
			cin >> x;
			a.push_back(x);
		}else if(s=="DELETE"){
			if(!a.empty())
				a.pop_back();
		}else if(s=="SAVE"){
			ll y;
			cin >> y;
			if(mp[y]==0){
				mp[y]=cnt;
				cnt++;
			}
			y = mp[y];
			note[y].clear();
			rep(i,a.size()){
				note[y].push_back(a[i]);
			}
		}else{
			ll z;
			cin >> z;
			a.clear();
			if(mp[z]!=0){
				z = mp[z];
				rep(i,note[z].size()){
					a.push_back(note[z][i]);
				}
			}
		}
		if(!a.empty())
			cout << a[a.size()-1] << ' ';
		else
			cout << -1 << ' ';
	}cout<<endl;
}