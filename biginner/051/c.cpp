#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	ll sx,sy,tx,ty;
	cin >> sx >> sy >> tx >> ty;
	rep(i,ty-sy)cout << "U";
	rep(i,tx-sx)cout << "R";
	rep(i,ty-sy)cout << "D";
	rep(i,tx-sx)cout << "L";
	cout << "L";
	rep(i,ty-sy+1)cout << "U";
	rep(i,tx-sx+1)cout << "R";
	cout << "D";
	cout << "R";
	rep(i,ty-sy+1)cout << "D";
	rep(i,tx-sx+1)cout << "L";
	cout << "U";
	cout << endl;
}