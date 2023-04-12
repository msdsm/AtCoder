//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt[100010];
ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<ll> p(m);
	string s[m];
	set<ll> st;
	rep(i,m){
		cin >> p[i] >> s[i];
	}
	rep(i,m){
		if(s[i]=="AC")
			st.insert(p[i]);
		else{
			if(st.count(p[i])>0)
				continue;
			else
				cnt[p[i]]++;
		}
	}
	rep(i,100010){
		if(st.count(i)>0)
			ans+=cnt[i];
	}
	cout << st.size() << ' ' << ans << endl;
}