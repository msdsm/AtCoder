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
	ll a,b,w;
	cin >> w >> a >> b;
	ll min = (a<b?a:b);
	ll max = (a<b?b:a);
	if(min+w<=max)
		cout << max-min-w << endl;
	else
		cout << 0 << endl;
}