#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll a[51],b[51],c[51],d[51];

ll f(ll x1,ll x2,ll y1,ll y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main(){
	int n,m;
	cin >> n >> m;
	rep(i,n){
		cin >> a[i] >> b[i];
	}
	rep(i,m){
		cin >> c[i] >> d[i];
	}
	ll ans,num;
	rep(i,n){
		ans = 1;
		num = f(a[i],c[0],b[i],d[0]);
		arep(1,j,m){
			if(num>f(a[i],c[j],b[i],d[j])){
				ans=j+1;
				num=f(a[i],c[j],b[i],d[j]);
			}
		}
		cout << ans << endl;
	}
}