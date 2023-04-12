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
	ll  n;
	cin >> n;
	if(n%10==3)
		cout << "bon" << endl;
	else if(n%10==0||n%10==1||n%10==6||n%10==8)
		cout << "pon" << endl;
	else
		cout << "hon" << endl;
}