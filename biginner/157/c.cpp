#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int a[4];

int main(){
	int n,m;
	cin>>n>>m;
	int tmp1,tmp2;
	rep(i,m){
		cin>>tmp1>>tmp2;
		if(a[tmp1-1]==0||a[tmp1-1]==tmp2)
			a[tmp1-1]=tmp2;
		else{
			cout << -1 << endl;
			return 0;
		}
	}
	if(a[0]){
		rep(i,n){
			cout << a[i];
		}
		cout << endl;
	}
	else{
		if(n==1)
			cout << 0 << endl;
		else
			cout << -1 << endl;
	}
//cout << a[0] << a[1] << a[2] << endl;
}