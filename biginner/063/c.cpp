#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll sum;
ll diff=101;//１０の倍数でない最小の整数　ない場合は１０１

int main(){
	ll n;
	cin >> n;
	ll s[n];
	cinf(s,n);
	rep(i,n){
		sum+=s[i];
		if(s[i]%10!=0){
			if(diff>s[i])
				diff=s[i];
		}
	}
	if(sum%10==0){
		if(diff!=101)
			sum-=diff;
		else
			sum=0;
	}
	cout << sum << endl;
}