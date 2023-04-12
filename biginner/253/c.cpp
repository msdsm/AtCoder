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
	ll Q;
	cin >> Q;
	map<ll,ll> mp;
	set<ll> st;
	rep(iii,Q){
		int t;
		cin >> t;
		if(t==1){
			ll x;
			cin >> x;
			mp[x]++;
			st.insert(x);
		}else if(t==2){
			ll x,c;
			cin >> x >> c;
			if(mp[x]>c)
				mp[x] -= c;
			else{
				mp[x] = 0;
				st.erase(x);
			}
		}else{
			ll min = *st.begin();
			auto itr = st.end();
			itr--;
			ll max = *itr;
			cout << max - min << endl;
		}
	}
}