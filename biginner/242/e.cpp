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

ll mod = 998244353;

ll f(string s){
	ll ret = 0;
	rep(i,s.length()){
		ret *= 26;
		ret %= mod;
		ret += (s[i]-'A');
		ret %= mod;
	}
	return ret;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll T;
	cin >> T;
	ll n;
	string s;
	ll ans;
	while(T--){
		cin >> n;
		cin >> s;
		if(n%2==0){
			ans = f(s.substr(0,n/2));
			string t = s.substr(0,n/2);
			reverse(t.begin(),t.end());
			if(t<=s.substr(n/2,n/2))
				ans++;
		}else{
			ans = f(s.substr(0,n/2));
			ans *= 26;
			ans %= mod;
			ans += s[(n-1)/2]-'A';
			string t = s.substr(0,n/2);
			reverse(t.begin(),t.end());
			if(t<=s.substr(n/2+1,n/2))
				ans++;
		}
		cout << ans%mod << endl;
	}
}