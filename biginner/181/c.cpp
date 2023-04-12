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
	ll n;
	cin >> n;
	ll x[n];
	ll y[n];
	rep(i,n){
		cin >> x[i] >> y[i];
	}

	rep(i,n){
		arep(i+1,j,n){
			arep(j+1,k,n){
				if((y[k]-y[i])*(x[j]-x[i])==(y[j]-y[i])*(x[k]-x[i])){
					cout << "Yes" << endl;
					exit(0);
				}
			}
		}
	}
	cout << "No" << endl;
}