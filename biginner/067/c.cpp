#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll tmp;

int main(){
	ll n;
	cin >> n;
	ll sum[n];//sum[i]は山の上1枚目からi+1枚目までの総和
	rep(i,n){
		cin >> tmp;
		if(i==0)
			sum[i]=tmp;
		else
			sum[i]=sum[i-1]+tmp;
	}
	ll min = abs(sum[n-1]-sum[0]-sum[0]);
	arep(1,i,n-1){
		tmp=abs(sum[n-1]-2*sum[i]);
		if(tmp<min)
			min=tmp;
	}
	cout << min << endl;
}