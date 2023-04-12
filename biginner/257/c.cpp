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

using P = pair<ll, bool>;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll cnt=0;
	rep(i,n){
		if(s[i]=='1')
			cnt++;
	}
	vector<ll> w(n);
	cinf(w,n);
	vector<P> p(n);
	rep(i,n){
		p[i].fst = w[i];
		if(s[i]=='0')
			p[i].snd = false;
		else
			p[i].snd = true;
	}
	sort(p.begin(),p.end());
/*
	cout << "debug start" << endl;
	rep(i,n){
		cout << p[i].fst << ' ' << p[i].snd << endl;
	}
	cout << "debug end" << endl;
*/
	ll ans = cnt;
	ll tmp = cnt;
	ll pre = -1;
	rep(i,n){
		if(p[i].snd==false)
			cnt++;
		if(p[i].snd==true)
			cnt--;
		if(pre!=p[i].fst){
			if(cnt>ans){
				ans = cnt;
			}
		}
		pre = p[i].fst;
	}
	if(cnt>ans){
		ans = cnt;
	}
	cout << ans << endl;
}