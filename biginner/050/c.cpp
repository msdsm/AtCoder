#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll a[100001];
ll ans[100001];
ll cnt[100001];
ll sum=1;
int mod = 1e9+7;

ll fact(ll num){
	ll tmp=1;
	while(num){
		tmp*=(num%mod);
		tmp%=mod;
		num--;
	}
	return tmp%mod;
}

int main(){
	ll n;
	cin >> n;
	rep(i,n){
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a,a+n);
	rep(i,n){
		if(i%2==0)
			ans[i/2]=a[n-i-1];
		else
			ans[n-(i+1)/2]=a[n-i-1];
	}
	rep(i,n){
		if(ans[i]!=abs(n-2*i-1)){
			cout << "0" << endl;
			return 0;
		}
	}
	rep(i,n){
		if(cnt[i]!=0){
			sum*=fact(cnt[i])%mod;
		}
	}
	cout << sum%mod << endl;
}