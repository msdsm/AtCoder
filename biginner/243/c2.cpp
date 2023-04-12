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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<pair<pll,char> > p(n);
	rep(i,n){
		ll x,y;
		cin >> x >> y;
		p[i].fst.fst = y;
		p[i].fst.snd = x;
	}
	string s;
	cin >> s;
	rep(i,n){
		p[i].snd = s[i];
	}
	sort(p.begin(),p.end());
/*
	cout << "debug start" << endl;
	rep(i,n){
		cout << p[i].fst.fst << ' ' << p[i].fst.snd << ' ' << p[i].snd << endl;
	}
	cout << "debug end" << endl;
	*/
	ll maxL = -1;
	ll minR = inf;
	rep(i,n){
		if(i==0){
			if(p[i].snd=='R')
				minR=p[i].fst.snd;
			else
				maxL=p[i].fst.snd;
		}
		else if(p[i].fst.fst==p[i-1].fst.fst){
			if(p[i].snd=='R'){
				minR = min(minR,p[i].fst.snd);
			}
			else{
				maxL = max(maxL,p[i].fst.snd);
			}
		}else{
			maxL = -1;
			minR = inf;
			if(p[i].snd=='R')
				minR=p[i].fst.snd;
			else
				maxL=p[i].fst.snd;
		}
		if(minR<maxL){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}