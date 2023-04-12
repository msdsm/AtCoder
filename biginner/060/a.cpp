#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool flag1,flag2;

int main(){
	string a,b,c;
	cin >> a >> b >> c;
	if(a[a.length()-1]==b[0])
		flag1=true;
	if(b[b.length()-1]==c[0])
		flag2=true;
	if(flag1&&flag2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}