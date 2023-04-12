#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ull ans;
ll tmp;

int main(){
	ll n,x,m;
	cin >> n >> x >> m;
	ans=x;
	tmp=x;
	arep(1,i,n){
		tmp=tmp*tmp%m;
		if(tmp==0)
			break;
		if(tmp==1){
			cout << ans+tmp*(n-i+1) << endl;
			return 0;
		}
		ans+=tmp;

cout << i << ':' << tmp << endl;
	}
	cout << ans << endl;
}