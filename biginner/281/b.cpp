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
	ll idx=0;
	ll cnt = 0;
	while(idx!=s.length()){
		if(cnt%3==0){
			if(s[idx]>='A' && s[idx]<='Z'){
				idx++;
			}else{
				cout << "No" << endl;
				return 0;
			}
		}else if(cnt%3==1){
			string t="";
			while(!(s[idx]>='A'&&s[idx]<='Z') && idx!=s.length()){
				t.push_back(s[idx]);
				idx++;
			}
			if(t==""){
				cout << "No" << endl;
				return 0;
			}
			ll num = stol(t);
			if(num>=100000 && num<=999999){
				;
			}else{
				cout << "No" << endl;
				return 0;
			}
		}else{
			if(s[idx]>='A' && s[idx]<='Z'){
				idx++;
			}else{
				cout << "No" << endl;
				return 0;
			}
		}
		cnt++;
	}
	cout << "Yes" << endl;
}