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
	string s;
	cin >> s;
	set<char> st;
	rep(i,n){
		st.insert(s[i]);
	}
	if(st.size()==1){
		cout << -1 << endl;
		return 0;
	}
	vector<ll> v;
	rep(i,n){
		if(s[i]=='-')
			v.push_back(i);
	}
	ll ans = 0;
	rep2(1,i,v.size()){
		ll tmp = v[i]-v[i-1]-1;
		if(tmp>ans)
			ans = tmp;
	}
	if(ans<v[0])
		ans=v[0];
	if(ans<n-v[v.size()-1]-1)
		ans = n-v[v.size()-1]-1;
	cout << ans << endl;
}