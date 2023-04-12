//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int a,b;
	cin >> a >> b;
	a+=b;
	if(a>=15&&b>=8)
		cout << 1 << endl;
	else if(a>=10&&b>=3)
		cout << 2 << endl;
	else if(a>=3)
		cout << 3 << endl;
	else
		cout << 4 << endl;
}