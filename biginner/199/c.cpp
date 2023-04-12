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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll q;
	cin >> q;
	rep(i,q){
		ll t,a,b;
		cin >> t >> a >> b;
		if(t==1){
			char c = s[b-1];
			s[b-1] = s[a-1];
			s[a-1] = c;
		}else{
			string u = s.substr(0,n);
			string v = s.substr(n,n);
			s = v+u;
		}
	}
	cout << s << endl;
}