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
	ll n,q;
	cin >> n >> q;
	vector<pll> p(n-1);
	pcin(p,n-1);
	vector<ll> c(q),d(q);
	rep(i,q)cin>>c[i]>>d[i];
	ll dist1[n],dist2[n];
	rep(i,n){
		dist1[i]=-1;
		dist2[i]=-1;
	}
	rep(i,n-1){
		dist1[p[i].fst-1]=p[i].snd;
		dist2[p[i].snd-1]=p[i].fst;
	}
	ll s,g;
	vector<ll> cnt(n);
	rep(i,n)cnt[i]=0;
	rep(i,n-1){
		cnt[p[i].fst-1]++;
		cnt[p[i].snd-1]++;
	}
	bool flag=false;
	rep(i,n){
		if(cnt[i]==1){
			if(flag)
				s = i+1;
			else{
				g = i+1;
				flag = true;
			}
		}
	}
	vector<ll> x(n);
	vector<ll> y(n);
	y[0]=s;
	y[1]=((dist1[s-1]==-1)?dist2[s-1]:dist1[s-1]);
	y[n-1]=g;

	cout << "debug start" << endl;
	cout << s << endl;
	cout << g << endl;
	cout << "debug end" << endl;
	
	
	rep2(2,i,n-1){

		cout << "debug start" << endl;
		cout << i << endl;
		cout << "debug end" << endl;
		
	
		if(dist1[y[i-1]-1]!=y[i-2])
			y[i]=dist1[y[i-1]-1];
		else
			y[i]=dist2[y[i-1]-1];
	}
	rep(i,n)x[y[i]-1]=i;

/*
cout << "debug start" << endl;
cout << s << endl;
cout << g << endl;
cout << "debug end" << endl;


	cout << "debug start" << endl;
	rep(i,n)cout << y[i] << endl;
	cout << "debug end" << endl;
*/	
	
	rep(t,q){
		if((x[d[t]-1]-x[c[t]-1])%2==0)
			cout << "Town" << endl;
		else
			cout << "Road" << endl;
	}
}