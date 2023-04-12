//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ld f(ld x, ld y){
	return sqrt(x*x+y*y);
}

int main(){
	ld pi = acos(-1);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	cout<<fixed<<setprecision(20);
	int n;
	cin >> n;
	int x,y,xn,yn;
	cin >> x >> y;
	cin >> xn >> yn;
	ld r = f(static_cast<ld>(x-xn),static_cast<ld>(y-yn))/2;
/*
	cout << "debug start" << endl;
	cout << r << endl;
	cout << "debug end" << endl;
*/	
	
	ld tmp = (2*r*r-f(static_cast<ld>(x-xn)/2-r,static_cast<ld>(y-yn)/2)*f(static_cast<ld>(x-xn)/2-r,static_cast<ld>(y-yn)/2))/(2*r*r);
	ld th = acos(tmp);
	if(y-yn<0)th=2*pi-th;
	/*
	cout << "debug start" << endl;
	cout << th << endl;
	cout << "debug end" << endl;
	*/
	
	cout << r*cos(2*pi/n+th)+static_cast<ld>(x+xn)/2 << ' ' << r*sin(th+2*pi/n)+static_cast<ld>(y+yn)/2 << endl;
}