#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
#define max(a,b) ((a)<(b)?(b):(a))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a<=0&&b<=0&&c>=0&&d>=0)
		cout << b*c << endl;
	else if(a>=0&&b>=0&&c<=0&&d<=0)
		cout << a*d << endl;
	else
		cout << max(a*c,b*d) << endl;
}