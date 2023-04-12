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
	ll a,x,m,s,t,num,tn;
	cin >> a >> x >> m;
	a %= m;
	if(x<m+1){
		ll tmp = 1;
		rep(i,x){
			ans += tmp;
			ans %= m;
			tmp *= a;
			tmp %= m;
		}
		cout << ans << endl;
		return 0;
	}
	vector<ll> v;
	v.push_back(1);
	set<ll> st;
	st.insert(1);
	while(true){
		ll tmp = (v.back()*a)%m;
		if(st.count(tmp)){
			ll idx = 0;
			while(v[idx]!=tmp)
				idx++;
			s = idx;
			t = v.size()-s;
			tn = v.back();
			break;
		}else{
			v.push_back(tmp);
			st.insert(tmp);
		}
	}
	ll tmp = 1;
	rep(i,s){//周期に入るまで
		ans += tmp%m;
		tmp *= a;
	}
	num = (x-s)/t;
	ll r = x-t*num-s;
	ll sum = 0;
	rep(i,v.size()){
		sum += v[i]%m;
		sum %= m;
	}
	ans += sum*num%m;
	ans %= m;
	tmp = tn;
	rep(i,r){
		tmp *= a;
		tmp %= m;
		ans += tmp;
		ans %= m;
	}
	cout << ans << endl;
}