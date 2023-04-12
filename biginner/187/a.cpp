#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int s(int x){
	int sum=0;
	while(x){
		sum += x%10;
		x/=10;
	}
	return sum;
}

int main(){
	int a,b;
	cin >> a >> b;
	if(s(a)<s(b))
		cout << s(b) << endl;
	else
		cout << s(a) << endl;
}