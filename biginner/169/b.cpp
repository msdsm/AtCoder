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
	ull a[n];
	cinf(a,n);
	sort(a,a+n);
	ull ans=1;
	for(ll i=0;i<n;i++){
		ans*=a[i];
		if(ans>1000000000000000000){
			cout << "-1" << endl;
			return 0;
		}
		if(ans==0){
			cout << "0" << endl;
			return 0;
		}
	}
	cout << ans << endl;
}