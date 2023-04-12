#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll f(ll x){
	return (pow(10,x)-1)/9;
}

int main(){
	ll tmp;
	cin >> tmp;
	ll k = tmp;
	if(k%7==0)
		k = k/7;
	arep(1,i,tmp){
		if(f(i)%k==0){
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
}