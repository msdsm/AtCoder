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
	ll k;
	cin >> k;
	ll max = 0;
	ll ans=0;
	ll cnt=0;
	queue<ll> t;
	rep(i,s.length()){
		if(s[i]=='.'){
			cnt++;
			t.push(i);
			ans++;
			if(cnt>k){
				ans = i-t.front();
				t.pop();
			}
		}else{
			ans++;
		}
		if(ans>max)
			max=ans;
	}
	cout << max << endl;
}