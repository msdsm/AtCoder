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
	int x,a,b;
	cin >> x >> a >> b;
	if(a>=b)
		cout << "delicious" << endl;
	else{
		if(b-a>x)
			cout << "dangerous" << endl;
		else
			cout << "safe" << endl;
	}
}