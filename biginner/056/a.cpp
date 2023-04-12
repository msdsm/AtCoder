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
	char a,b;
	cin >> a >> b;
	switch(a){
		case 'H':cout<<b<<endl;break;
		case 'D':if(b=='H')cout<<'D'<<endl;else cout<<'H'<<endl;break;
	}
}