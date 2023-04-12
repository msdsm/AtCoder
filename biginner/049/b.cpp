#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

char s[101][101];
char d[202][101];

int main(){
	int h,w;
	cin >> h >> w;
	rep(i,h)rep(j,w)cin >> s[i][j];
	rep(i,h){
		rep(j,w){
			d[2*i][j]=s[i][j];
			d[2*i+1][j]=s[i][j];
		}
	}
	rep(i,2*h){
		rep(j,w){
			cout << d[i][j];
		}
		cout << endl;
	}
}