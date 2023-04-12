#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool ev(int x){
	if(x%2==0)
		return true;
	else
		return false;
}

int main(){
	ll a,b,c,d;
	cin >> a >> b;
	cin >> c >> d;
	if(a==b&&c==d){
		cout << 0 << endl;
		return 0;
	}
	if(abs(a-c)+abs(b-d)<3)
		cout << 1 << endl;
	ll tmp;
	if((a<c&&b<d)||(c<a,d<b))
		tmp = abs(d-c-b+a);
	else
		tmp = abs(c+d-a-b);
	if(tmp==0)
		cout << 1 << endl;
	else if(tmp<=3)
		cout << 2 << endl;
	else{
		if((ev(a+b+c-d)&&ev(a+b-c+d))||(ev(c+d+a-b)&&ev(c+d-a+b)))
			cout << 2 << endl;
		else
			cout << 3 << endl;
	}
}