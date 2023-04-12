#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt1,cnt2,cnt3;//奇数、2、4

int main(){
	ll n;
	cin >> n;
	ll a[n];
	cinf(a,n);
	rep(i,n){
		if(a[i]%4==0)
			cnt3++;
		else if(a[i]%2==0)
			cnt2++;
		else
			cnt1++;
	}
	if(n%2){
		if(cnt3>=cnt1-1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}else{
		if(cnt3>=cnt1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}