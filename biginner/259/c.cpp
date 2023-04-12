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
	string s,t,u;
	cin >> s;
	cin >> t;
	ll i = 0;
	ll cnt = 0;
	char c;
	while(i<t.length()){
		if(i==0){
			c = t[i];
			cnt++;
			i++;
			continue;
		}
		if(t[i]==c){
			cnt++;
		}else{
			if(cnt>=2){
				u.push_back(c);
				u.push_back(c);
			}else{
				u.push_back(c);
			}
			cnt = 1;
			c = t[i];
		}
		i++;
	}
	if(cnt>=2){
		u.push_back(c);
		u.push_back(c);
	}else{
		u.push_back(c);
	}
	//cout << u << endl;
	if(u!=s)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}