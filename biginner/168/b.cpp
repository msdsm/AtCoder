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
	char s[1000];
	ll k;
	cin >> k;
	cin >> s;
	if(strlen(s)<=k)
		cout << s << endl;
	else{
		rep(i,k){
			cout << s[i];
		}
		cout << "..." << endl;
	}
}