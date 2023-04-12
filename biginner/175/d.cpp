#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll p[5001];
ll c[5001];

int main(){
	ll n,k;
	cin >> n >> k;
	ll tmp;
	cinf(p,n);
	cinf(c,n);
	ll start=0;
	ll ans=c[p[0]-1];
//cout << ans << endl;
	rep(i,n){
		start=i;
		tmp=0;
		rep(j,k){
			tmp+=c[p[start]-1];
			start=p[start]-1;
			if(ans<tmp)ans=tmp;
		}
//cout << tmp[j] << " " << ans << endl;
	}
	cout << ans << endl;
}