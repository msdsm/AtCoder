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
	string s;
	cin >> s;
	set<pll> st;
	pll p = pll(0,0);
	st.insert(p);
	rep(i,n){
		if(s[i]=='R'){
			p.fst++;
			if(st.count(p)>0){
				cout << "Yes" << endl;
				return 0;
			}
			st.insert(p);
		}else if(s[i]=='L'){
			p.fst--;
			if(st.count(p)>0){
				cout << "Yes" << endl;
				return 0;
			}
			st.insert(p);
		}else if(s[i]=='U'){
			p.snd++;
			if(st.count(p)>0){
				cout << "Yes" << endl;
				return 0;
			}
			st.insert(p);
		}else{
			p.snd--;
			if(st.count(p)>0){
				cout << "Yes" << endl;
				return 0;
			}
			st.insert(p);
		}
	}
	cout << "No" << endl;
}