#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	ll n,a,b;
	cin >> n >> a >> b;
	ll q = n/(a+b);
	ll r = n%(a+b);
	if(r < a)
		cout << q*a+r << endl;
	else
		cout << (q+1)*a << endl;
}