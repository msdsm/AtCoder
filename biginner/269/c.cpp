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
	ll x;
	cin >> x;
	set<ll> st;
	ll xx = x;
	vector<ll> v;
	ll cnt = 0;
	while(xx){
		if(xx%2)
			v.push_back(cnt);
		xx/=2;
		cnt++;
	}
	ll n = v.size();
	for(ll bits=0; bits<(1<<n);bits++){
		ll mask = 0;
		rep(i,n){
			if(bits & (1<<i)){
				mask += (1<<v[i]);
			}
		}
		st.insert(x^mask);
	}
	for(auto itr=st.begin();itr!=st.end();itr++){
		cout << *itr << endl;
	}
}