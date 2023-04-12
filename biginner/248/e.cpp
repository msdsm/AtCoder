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

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,k;
	cin >> n >> k;
	vector<pll> p(n);
	pcin(p,n);
	if(k==1){
		cout << "Infinity" << endl;
		return 0;
	}
	set<pair<ll,pll> > st;
	rep(i,n){
		rep2(i+1,j,n){
			ll x1 = p[i].fst;
			ll y1 = p[i].snd;
			ll x2 = p[j].fst;
			ll y2 = p[j].snd;
			ll g = gcd(abs(y2-y1),abs(x2*y1-x1*y2));
			g = gcd(abs(x2-x1),g);
			ll a = (x2-x1)/g;
			ll b = (y2-y1)/g;
			ll c = (x2*y1-x1*y2)/g;
			if(a==0){
				st.insert(pair<ll,pll>(0,pll(x1,x2)));
			}else if(a<0){
				a *= -1;
				b *= -1;
				c *= -1;
				st.insert(pair<ll,pll>(a,pll(b,c)));
			}else{
				st.insert(pair<ll,pll>(a,pll(b,c)));
			}
		}
	}
	for(auto itr = st.begin();itr!=st.end();itr++){
		pair<ll,pll> tmp = *itr;
		ll a = tmp.fst;
		ll b = tmp.snd.fst;
		ll c = tmp.snd.snd;
		ll cnt = 0;
		rep(i,n){
			if(a==0){
				if(p[i].fst==b)
					cnt++;
			}else{
				if(a*p[i].snd==b*p[i].fst+c)
					cnt++;
			}
		}
		if(cnt>=k)
			ans++;
	}
	cout << ans << endl;
}