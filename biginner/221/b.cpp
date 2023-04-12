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
	string s,t;
	cin >> s >> t;
	if(s==t){
		cout << "Yes" << endl;
		return 0;
	}
	int n=0;
	rep(i,s.length()){
		if(s[i]!=t[i]){
			n = i;
			break;
		}
	}
	if(n==s.length()-1){
		cout << "No" << endl;
		return 0;
	}
	char c = s[n];
	s[n] = s[n+1];
	s[n+1] = c;
	if(s==t)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}