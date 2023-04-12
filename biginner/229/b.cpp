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

ll digit(ll x){
	ll cnt=0;
	while(x){
		x/=10;
		cnt++;
	}
	return cnt;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll a,b;
	cin >> a >> b;
	while(min(a,b)){
		int tmp1 = a%10;
		int tmp2 = b%10;
		if(tmp1+tmp2>=10){
			cout << "Hard" << endl;
			return 0;
		}
		a/=10;
		b/=10;
	}
	cout << "Easy" << endl;
}