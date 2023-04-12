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
	ld a,b,h,m;
	cin >> a >> b >> h >> m;
	cout << setprecision(15) << sqrt(a*a+b*b-2*a*b*cos(abs((m/30)*acos(-1)-(h/6+m/360)*acos(-1)))) << endl;
}