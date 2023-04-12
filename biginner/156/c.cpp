#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll f(ll *x,ll n,ll p){
	ll sum=0;
	rep(i,n){
		sum+=pow((x[i]-p),2);
	}
	return sum;
}

int main(){
	ll n;
	cin >> n;
	ll x[n];
	cinf(x,n);
	sort(x,x+n);
	ll left=x[0];
	ll right=x[n-1];
	ll min=f(x,n,left);
	arep(left+1,i,right+1){
		ll tmp=f(x,n,i);
		if(tmp<min)min=tmp;
	}
	cout << min << endl;
}