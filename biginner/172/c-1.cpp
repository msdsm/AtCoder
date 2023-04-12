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
	ll n,m,k;
	cin >> n >> m >> k;
	ll a[n];
	cinf(a,n);
	ll b[m];
	cinf(b,m);
	ull sum=0;
	ll cnt=0;
	ll i=0,j=0;
	while(sum<=k){
		if(a[i]<b[j]){
			if(a[i]>k-sum)
				break;
			sum+=a[i];
			i++;
			cnt++;
		}else{
			if(b[j]>k-sum)
				break;
			sum+=b[j];
			j++;
			cnt++;
		}
	}
	cout << cnt << endl;
}