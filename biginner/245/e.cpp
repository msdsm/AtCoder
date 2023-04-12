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
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n),b(n),c(m),d(m);
	cinf(a,n);
	cinf(b,n);
	cinf(c,m);
	cinf(d,m);
	vector<pll> v;
	rep(i,n){
		v.push_back(pll(a[i],i));
	}
	rep(i,m){
		v.push_back(pll(c[i],i+n));
	}
	sort(v.begin(),v.end(),greater<pll>());
/*
	cout << "debug start v" << endl;
	rep(i,v.size()){
		cout << i << ':' << v[i].fst << ',' << v[i].snd << endl;
	}
	cout << "debug end" << endl;
*/	
	
	multiset<ll> ms;
	rep(i,m+n){
		pll tmp = v[i];
/*
		cout << "debug start i" << endl;
		cout << i << ':' << endl;
		cout << "debug end" << endl;
*/		
		
		if(tmp.snd>=n){
/*
			cout << "debug start msinsert" << endl;
			cout << d[tmp.snd-n] << endl;
			cout << "debug end" << endl;
*/			
			
			ms.insert(d[tmp.snd-n]);
		}else{
/*
			cout << "debug start ms" << endl;
			for(auto itr=ms.begin();itr!=ms.end();itr++)cout<<*itr<<' ';
			cout<<endl;
			cout << "debug end" << endl;
*/
/*
			cout << "debug start b" << endl;
			cout << b[tmp.snd] << endl;
			cout << "debug end" << endl;
*/			
			
			
			
			auto itr = ms.lower_bound(b[tmp.snd]);
/*
			cout << "debug start itr" << endl;
			cout << *itr << endl;
			cout << "debug end" << endl;
*/			
			
			if(itr==ms.end()){
				cout << "No" << endl;
				return 0;
			}else{
				ms.erase(itr);
			}
		}
	}
	cout << "Yes" << endl;
}