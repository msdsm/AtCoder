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
	ll n,k;
	cin >> n >> k;
	vector<string> s(n);
	rep(i,n){
		cin >> s[i];
	}
	ll ans = 0;
	for(ll bit = 0; bit < (1<<n); ++bit){	
		vector<int> tmp(26);
		rep(i,n){
			if(bit & (1<<i)){
				rep(j,s[i].length()){
					tmp[s[i][j]-'a']++;
				}
			}
		}
		ll cnt = 0;
		rep(i,26){
			if(tmp[i]==k)
				cnt++;
		}
		if(cnt>ans)
			ans=cnt;
	}
	cout << ans << endl;
}