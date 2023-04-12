#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll prime[1001];
ll ans=1;
ll cnt,tmp;

int main(){
	int mod = 1e9+7;
	ll n;
	cin >> n;
	prime[0]=1;
	prime[1]=1;
	for(int i=0;i<1001;i++){
		if(prime[i]==0){
			for(int j=2*i;j<1001;j+=i){
				prime[j]++;
			}
		}
	}
	rep(i,n+1){
		cnt=0;
		if(prime[i]==0){
			arep(1,j,n+1){
				//cout << "j:" << j << endl;
				tmp=j;
				while(tmp){
					if(tmp%i==0)
						cnt++;
					else
						break;
					tmp/=i;
				}
			}
		}
		//cout << i << ':' << cnt << endl;
		cnt=(cnt+1)%mod;
		ans*=cnt;
		ans%=mod;
	}
	//rep(i,1001)if(prime[i]==0)cout << i << endl;
	cout << ans%mod << endl;
}