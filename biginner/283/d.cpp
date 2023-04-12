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
	string s;
	cin >> s;
	ll n = s.length();
	ll c = 0;
	vector<set<char> > v(n);
	vector<bool> used(26);
	rep(i,n){
		if(s[i]=='('){
			c++;
		}else if(s[i]==')'){
			for(auto itr = v[c].begin();itr!=v[c].end();itr++){
				char tmp = *itr;
				used[tmp-'a']=false;
			}
			v[c].clear();
			c--;
		}else{
/*
			cout << "debug start" << endl;
			cout << v[c].count(s[i]) << endl;
			cout << "debug end" << endl;
*/			
			
			if(used[s[i]-'a']){
				cout << "No" << endl;
				return 0;
			}
			v[c].insert(s[i]);
			used[s[i]-'a']=true;
		}
	}
	cout << "Yes" << endl;
}