//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
#define fst first
#define snd second
#define pcin(x,n) for(ll i=0;i<(n);i++)cin>>x[i].fst>>x[i].snd;
#define pdebug(x) cout << '(' << x.fst << ',' << x.snd << ")\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll x;
	cin >> x;
	ll y = x;
	int digit=0;
	while(y){
		y/=10;
		digit++;
	}
	//cout << digit << endl;
	if(digit<3){
		cout << x << endl;
		return 0;
	}
	y = x;
	rep(i,digit-2)y/=10;
	int top = 10*(y/10) + y%10;
	//cout << top << endl;
	int r = digit-2;//残り
	while(true){
		int a1 = top/10;
		int a2 = top%10;
		int d = a2 - a1;
		//cout << a1 << endl;
		//cout << a2 << endl;
		//cout << d << endl;
		if(a2+r*d<=9 && a2+r*d>=0){
			ans = top;
			rep(i,r){
				ans*=10;
				ans+=(a2+(i+1)*d);
			}
			if(ans>=x){
				break;
			}
		}
		top++;
		if(top==100){
			top = 10;
			r++;
		}
	}
	cout << ans << endl;
}