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

ull f1(ld x,ld y,ld r){
	ull cnt=0;
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
	return cnt;
}

ull f2(ld x,ld y,ld r){
	ull cnt = 0;
	for(ll i = static_cast<ll>(y-r)-1;i<=static_cast<ll>(y+r)+1;i++){
		for(ll j = static_cast<ll>(x-r)-1;j<=static_cast<ll>(x+r)+1;j++){
			if((i-x)*(i-x) <= (r+j-y)*(r-j+y) )
				cnt++;
		}
	}
	return cnt;
}



int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ld x,y,r;
	srand(time(NULL));
	rep(i,10000){
		ld x = rand()%100+rand()%100/(rand()%100+1)-rand()%100;
		ld y = rand()%100+rand()%100/(rand()%100+1)-rand()%100;
		ld r = rand()%100+rand()%100/(rand()%100+1)+1;
		cout << ' ' << i << ' ';
		if(f1(x,y,r)==f2(x,y,r))
			cout << "Yes" << endl;
		else{
			cout << "No" << endl;
			cout << x << endl;
			cout << y << endl;
			cout << r << endl;
			cout << f1(x,y,r) << endl;
			cout << f2(x,y,r) << endl;
			exit(0);
		}
	}
}