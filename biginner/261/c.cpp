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
	vector<string> s(n);
	rep(i,n)cin>>s[i];
	set<string> st;
	map<string, ll> mp;
	rep(i,n){
		if(st.count(s[i])==0){
			cout << s[i] << endl;
			st.insert(s[i]);
			mp[s[i]]=1;
		}else{
			cout << s[i] << '(' << mp[s[i]] << ')' << endl;
			mp[s[i]]++;
		}
	}
}