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
	string o,e;
	cin >> o;
	cin >> e;
	if(o.length()==e.length()){
		rep(i,o.length()){
			cout<<o[i]<<e[i];
		}
		cout << endl;
	}else{
		rep(i,e.length()){
			cout<<o[i]<<e[i];
		}
		cout<<o[o.length()-1]<<endl;
	}
}