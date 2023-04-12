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
	ll k;
	cin >> k;
	for(ll i=1;i<10000000000000;i+=2){
		if( static_cast<ll>(log10(1+9*i*k))==log10(1+9*i*k)){
			cout << static_cast<ll>(log10(1+9*i*k)) << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
}