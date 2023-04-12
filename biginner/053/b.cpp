#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll a,z;
bool flag;

int main(){
	string s;
	cin >> s;
	rep(i,s.length()){
		if(s[i]=='A'&&!flag){
			flag=true;
			a=i;
		}
		if(s[i]=='Z')
			z=i;
	}
	cout << z-a+1 << endl;
}