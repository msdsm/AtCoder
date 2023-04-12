#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int ans;

int main(){
	string s;
	cin >> s;
	if(s=="RRR")
		ans=3;
	else if(s.substr(0,2)=="RR"||s.substr(1,2)=="RR")
		ans=2;
	else if(s=="SSS")
		ans=0;
	else
		ans=1;
	cout << ans << endl;
}