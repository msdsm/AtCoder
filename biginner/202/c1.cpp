//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin>>n;
	vector<ll> a(n),b(n),c(n);
	cinf(a,n);
	cinf(b,n);
	cinf(c,n);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	vector<pll> f(n);
	rep(i,b[0]-1){
		f[i].first=-1;
		f[i].second=-1;
	}
	vector<ll> tmp(n);
	rep(i,n){
		tmp[b[i]-1]++;
	}
	ll tmp2=0;
	rep(i,n){
		if(tmp[i]==0){
			f[i].first=-1;
			f[i].second=-1;
		}
		else{
			f[i].first=tmp2;
			f[i].second=tmp[i]-1+tmp2;
			tmp2=tmp[i];
		}
	}
	vector<ll> g(n);
	rep(i,n){
		g[c[i]-1]++;
	}
	rep2(1,i,n){
		g[i]+=g[i-1];
	}	
	rep(i,n){
		if(i==0&&f[a[i]-1].second==f[a[i]-1].first)
			cnt+=g[f[a[i]-1].second];
		else if(f[a[i]-1].first==0){
			cnt += g[f[a[i]-1].second];
		}
		else{
			if(f[a[i]-1].first==-1)
				continue;
			else
				cnt += g[f[a[i]-1].second]-g[f[a[i]-1].first-1];
		}
	}
	cout << cnt << endl;
}