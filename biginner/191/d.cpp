//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ull cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ld x,y,r;
	cin >> x >> y >> r;
	ll maxy = static_cast<ll>(y+r);
	if(static_cast<ll>(y+r)!=y+r && y+r<0)
		maxy--;

	ll miny = static_cast<ll>(y-r);
	if(static_cast<ll>(y-r)!=y-r && y-r>0)
		miny++;
	
	ll maxi,mini;
	for(ll i = miny; i<=maxy;i++){
		maxi = static_cast<ll>(x+sqrt((r-i+y)*(r+i-y)));
		mini = static_cast<ll>(x-sqrt((r-i+y)*(r+i-y)));

		if(x+sqrt((r-i+y)*(r+i-y))<0 && static_cast<ll>(x+sqrt((r-i+y)*(r+i-y)))!=x+sqrt((r-i+y)*(r+i-y)))
			maxi--;

		if(x-sqrt((r-i+y)*(r+i-y))>0 && static_cast<ll>(x-sqrt((r-i+y)*(r+i-y)))!=x-sqrt((r-i+y)*(r+i-y)))
			mini++;

		cnt+=maxi-mini+1;
	}
	cout << cnt << endl;
}