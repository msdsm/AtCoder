#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int num;

int main(){
	string n;
	cin >> n;
	rep(i,n.length()){
		num+=atoi(n.substr(i,1).c_str());
		num%=9;
	}
	if(num==0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}