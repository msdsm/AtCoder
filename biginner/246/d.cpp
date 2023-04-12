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

ll inf = numeric_limits<ll>::max();

ll f(ull a,ull b){
	if(a==0||b==0)return 0;
	ll tmp = b/a;
	if(1+tmp+tmp*tmp+tmp*tmp*tmp<inf/(a*a*a))
		return a*a*a + a*a*b + a*b*b + b*b*b;
	else
		return 0;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	ll tmp;
	ll a,b,c;
	ll ans=inf;
	for(tmp=0;tmp*tmp*tmp*4<=n;tmp++){
		a = tmp;
		b = tmp;
	}
	for(tmp=0;tmp*tmp*tmp<=n;tmp++){
		c = tmp;
	}
	for(ll i = max((ll)0,a-1000);i<a+1000;i++){
		for(ll j = max((ll)0,b-1000);j<b+1000;j++){
/*
			cout << "debug start" << endl;
			cout << i << endl;
			cout << j << endl;
			cout << f(i,j) << endl;
			cout << "debug end" << endl;
			
		*/	
			if(f(i,j)>=n){
				if(ans>f(i,j))
					ans=f(i,j);
			}
		}
	}
	if(c*c*c>=n && c*c*c<ans)
		ans=c*c*c;
	c++;
	if(c*c*c>=n && c*c*c<ans)
		ans=c*c*c;
	cout << ans << endl;
	//cout <<  << endl;
}