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
	ll a,b,c,k,sum=0;
	cin >> a >> b >> c >> k;
	if(k<=a)
		sum=k;
	else if(a<k && k<=(a+b))
		sum=a;
	else
		sum=2*a+b-k;
	cout << sum << endl;
}