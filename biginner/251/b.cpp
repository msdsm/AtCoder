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

ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,w;
	cin >> n >> w;
	vector<ll> a(n);
	cinf(a,n);
	vector<bool> ans(3000010);
	for(ll i = 0; i < n; i++){
		ans[a[i]-1]=true;
		for(ll j = 0; j < n; j++){
			if(i==j)
				continue;
			ans[a[i]+a[j]-1]=true;
			for(ll k = 0; k < n; k++){
				if(k==i || k==j)
					continue;
				ans[a[i]+a[j]+a[k]-1]=true;
			}
		}
	}
	rep(i,w){
		if(ans[i])
			cnt++;
	}
	cout << cnt << endl;
}