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
	ll h,w,n;
	cin >> h >> w >> n;
	vector<ll> a(n),b(n);
	rep(i,n)cin>>a[i]>>b[i];
	vector<pll> p1(n),p2(n);
	vector<ll> tmp1(n),tmp2(n);
	rep(i,n){
		tmp1[i]=a[i];
		tmp2[i]=b[i];
	}
	sort(tmp1.begin(),tmp1.end());
	sort(tmp2.begin(),tmp2.end());
	rep(i,n){
		p1[i].fst=tmp1[i];
		p2[i].fst=tmp2[i];
	}
	p1[0].snd=1;
	p2[0].snd=1;
	rep2(1,i,n){
		if(p1[i].fst==p1[i-1].fst)
			p1[i].snd=p1[i-1].snd;
		else
			p1[i].snd=p1[i-1].snd+1;

		if(p2[i].fst==p2[i-1].fst)
			p2[i].snd=p2[i-1].snd;
		else
			p2[i].snd=p2[i-1].snd+1;
	}
	rep(i,n){
		cout << p1[lower_bound(tmp1.begin(),tmp1.end(),a[i])-tmp1.begin()].snd << ' ' << p2[lower_bound(tmp2.begin(),tmp2.end(),b[i])-tmp2.begin()].snd << endl;
	}
}