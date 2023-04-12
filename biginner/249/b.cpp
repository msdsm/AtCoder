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
	map<char,int> mp;
	bool flag1 = false;
	bool flag2 = false;
	rep(i,s.length()){
		if(s[i]>='a' && s[i]<='z')
			flag1 = true;
		if(s[i]>='A' && s[i]<='Z')
			flag2 = true;
	}
	rep(i,s.length()){
		mp[s[i]]++;
	}
	bool flag3 = true;
	rep(i,s.length()){
		if(mp[s[i]]!=1){
			flag3 = false;
			break;
		}
	}
	if(flag1&&flag2&&flag3)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}