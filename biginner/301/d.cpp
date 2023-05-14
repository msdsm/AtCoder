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
	ll n;
	cin >> n;
	vector<ll> v;
	ll tmp = 0;
	rep(i,s.length()){
		if(s[i]=='1')
			tmp += powl(2, s.length()-i-1);
		else if(s[i]=='0')
			continue;
		else
			v.push_back(powl(2, s.length()-i-1));
	}
	if(tmp>n){
		cout << -1 << endl;
		return 0;
	}
	rep(i,v.size()){
		if(tmp+v[i]<=n)
			tmp+=v[i];
	}
	cout << tmp << endl;
}