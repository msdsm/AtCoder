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
	ll n;
	cin >> n;
	ll a[n];
	cinf(a,n);
	sort(a,a+n);
	ll ans=0;
	bool bl=false;
	rep(i,n){
		bl = false;
		rep(j,i){
			if(a[i]%a[j]==0)
				break;
			if(j==i-1)
				bl=true;
		}
		if(bl)
			ans++;
	}
	cout << ans << endl;
}