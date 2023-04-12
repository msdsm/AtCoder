#include <string.h>
#include <iostream>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int d[10];

bool check(ll num,ll k,const int* d){
	while(num){
		rep(i,k){
			if((num%10)==d[i])
				return false;
		}
		num/=10;
	}
	return true;
}

int main(){
	ll k,n;
	cin >> n >> k;
	rep(i,k){
		cin >> d[i];
	}
	rep(i,1e7){
		if(check(n+i,k,d)){
			cout << n+i << endl;
			return 0;
		}
	}
}