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
	vector<ll> a(n);
	cinf(a,n);
	ll max = 0;
	rep(i,n){
		if(max<a[i])
			max = a[i];
	}
	vector<ll> cnt(max+1);
	rep(i,n){
		cnt[a[i]]++;
	}
	set<ll> st;
	rep(i,n){
		st.insert(a[i]);
	}
	ll ans = 0;
	for(auto itr = st.begin();itr!=st.end();itr++){
		ll ai = *itr;
		ll num = 0;
		for(ll i = 1; i*i <= ai; i++){
			if(ai%i==0){
				ll aj = i;
				ll ak = ai/i;
				if(aj==ak)
					num += cnt[aj]*cnt[ak];
				else
					num += cnt[aj]*cnt[ak]*2;
			}
		}
		ans += num*cnt[ai];
	}
	cout << ans << endl;
}