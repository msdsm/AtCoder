#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
#define diff(a,b) ((a)>(b))?(a)-(b):(b)-(a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	ll x,n;
	cin >> x >> n;
	if(n==0){
		cout << x << endl;
		return 0;
	}
	ll p[n];
	cinf(p,n);
	sort(p,p+n);
	ll min=diff(x,x-n-1);	
	ll ans=x-n-101;
	ll j=0;
	arep(x-n-100,i,x+n+100){
		if(i==p[j]){
			j++;
			continue;
		}
		if(diff(x,i)<min){
			min=diff(x,i);
			ans=i;
		}
	}
	cout << ans << endl;
}