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
ll ans;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	string s;
	cin >> s;
	map<char, int> mp;
	string tmp = "atcoder";
	rep(i,tmp.length())mp[tmp[i]]=i;
	vector<ll> v;
	rep(i,s.length())v.push_back(mp[s[i]]);
/*
	cout << "debug start" << endl;
	rep(i,7)cout << v[i] << ' ';
	cout << "debug end" << endl;
*/	
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7 - i - 1; j++){
			if(v[j] > v[j+1]){
				swap(v[j],v[j+1]);
				ans++;
			}
		}
	}
	cout << ans << endl;
}