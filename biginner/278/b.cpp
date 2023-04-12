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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int h,m;
	cin >> h >> m;
	while(true){
		int a,b,c,d;
		b = h%10;
		a = (h/10)%10;
		d = m%10;
		c = (m/10)%10;
		int invh = 10*a+c;
		int invm = 10*b+d;
		if(invh>=0&&invh<=23&&invm>=0&&invm<=59){
			cout << h << ' '<< m << endl;
			return 0;
		}
		m++;
		if(m==60){
			h++;
			m=0;
			if(h==24){
				h=0;
			}
		}
	}
}