#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ull sum;
ll ans;
ll tmp;

int main(){
	ull x,y;
	ll a,b;
	cin >> x >> y >> a >> b;
	sum=x;
	while(sum<y){
		if(static_cast<ld>(sum)<static_cast<ld>(b)/(a-1)){
			sum*=a;
			ans++;
		}else{
			ans+=(y-sum-1)/b;
			cout << ans << endl;
			return 0;
		}
	}
	cout << ans-1 << endl;
}