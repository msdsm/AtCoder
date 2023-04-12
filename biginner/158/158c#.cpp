#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	ll a,b;
	cin >> a >> b;
	rep(i,1001){
		if(static_cast<ll>(0.08*i)==a && static_cast<ll>(0.10*i)==b){
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
}