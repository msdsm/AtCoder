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

ll d(pll p1,pll p2){
	return (p1.fst-p2.fst)*(p1.fst-p2.fst)+(p1.snd-p2.snd)*(p1.snd-p2.snd);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	cout<<fixed<<setprecision(20);
	ll n,k;
	cin >> n >> k;
	vector<ll> a(k);
	cinf(a,k);
	set<ll> st;
	rep(i,k){
		st.insert(a[i]-1);
	}
	vector<pll> p(n);
	ll ans = 0;
	pcin(p,n);
	rep(i,n){
		if(st.count(i)>0){
			continue;
		}else{
			ll min = numeric_limits<ll>::max();
			for(auto itr = st.begin();itr!=st.end();itr++){
				ll tmp = *itr;
				ll distance = d(p[i],p[tmp]);
				if(min>distance)
					min=distance;
			}
			if(ans<min){
				ans = min;
			}
		}
	}
	cout << sqrt(ans) << endl;
}