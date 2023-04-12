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
	ll n,k,x;
	cin >> n >> k >> x;
	vector<ll> a(n);
	cinf(a,n);
	vector<ll> v(n);
	rep(i,n){
		if(k>0){
			ll tmp1 = a[i]/x;
			ll tmp2 = a[i]%x;
			if(k>=tmp1){
				v[i]=tmp2;
				k -= tmp1;
			}else{
				v[i]=a[i]-k*x;
				k = 0;
			}
		}else{
			v[i]=a[i];
		}
/*
		cout << "debug start" << endl;
		cout << ans << endl;
		cout << k << endl;
		cout << "debug end" << endl;
	*/	
		
	}
	sort(v.begin(),v.end());
	ll ans = 0;
	rep(i,n-k)ans+=v[i];
	cout << ans << endl;
}