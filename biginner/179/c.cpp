#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ull cnt1;
ull cnt2;

int main(){
	ll n;
	cin >> n;
	arep(1,a,sqrt(n)+1){
		arep(a+1,b,n){
			if(a*b<n)
				cnt1++;
		}
	}

	arep(1,a,sqrt(n)+1){
		if(a*a<n)
			cnt2++;
	}

	cout << cnt1*2+cnt2 << endl;
}