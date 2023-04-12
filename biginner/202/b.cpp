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
	string s;
	cin >> s;
	reverse(s.begin(),s.end());
	rep(i,s.length()){
		switch(s[i]){
			case '0': s[i]='0';break;
			case '1': s[i]='1';break;
			case '6': s[i]='9';break;
			case '8': s[i]='8';break;
			case '9': s[i]='6';break;
		}
	}
	cout << s << endl;
}