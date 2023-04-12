#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	ll n,m,x;
	cin >> n >> m >> x;
	ll c[n],a[n][m],u[m];

	rep(i,n){
		cin >> c[i];
		rep(j,n){
			cin >> a[i][j];
		}
	}

	rep(i,m){
		u[i] = 0;
	}

	ll ans;

	

}