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
	ll n,l,r;
	cin >> n >> l >> r;
	vector<ll> a(n);
	cinf(a,n);
	ll ans = 0;
	rep(i,n)ans+=a[i];
	vector<ll> s(n);
	s[0]=a[0];
	rep2(1,i,n)s[i]=s[i-1]+a[i];
	
	vector<ll> ix;
	vector<ll> iy;
	vector<ll> dx(n),dy(n);
	rep(i,n){
		dx[i]=l-a[i];
		dy[i]=r-a[n-i-1];
	}
	rep2(1,i,n){
		if(dx[i-1]<=0 && dx[i]>=0){
			ix.push_back(i);
			ix.push_back(i+1);
		}
		if(dy[i-1]<=0 && dy[i]>=0){
			iy.push_back(i);
			iy.push_back(i+1);
		}
	}
	rep(i,ix.size()){
		rep(j,iy.size()){
			ll tmp;
			ll x = ix[i];
			ll y = iy[j];
			if(x+y>n-1)
				tmp = l*(n-y) + r*y;
			else
				tmp = l*x + r*y + s[n-y-1]-s[x-1];
			if(tmp<ans)
				ans=tmp;
		}
	}
	cout << ans << endl;
}