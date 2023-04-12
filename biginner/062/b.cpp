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
	int h,w;
	cin >> h >> w;
	char a[h][w];
	rep(i,h)rep(j,w)cin>>a[i][j];
	rep(i,w+2)cout<<'#';cout<<endl;
	rep(i,h){
		cout<<'#';
		rep(j,w){
			cout << a[i][j];
		}
		cout << '#' << endl;
	}
	rep(i,w+2)cout<<'#';cout<<endl;
}