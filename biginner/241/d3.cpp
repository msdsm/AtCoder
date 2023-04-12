#pragma GCC optimize("Ofast")
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll q;
	cin >> q;
	multiset<ll> ms;
	while(q--){
		int c;
		cin >> c;
		if(c==1){
			ll x;
			cin >> x;
			ms.insert(x);
		}else if(c==2){
			ll x,k;
			cin >> x >> k;
			auto itr = ms.upper_bound(x);
			bool flag = false;
			rep(i,k){
				if(itr!=ms.begin())
					itr--;
				else{
					flag = true;
					break;
				}
			}
			if(!flag)
				cout << *itr << endl;
			else
				cout << -1 << endl;
		}else{
			ll x,k;
			cin >> x >> k;
			auto itr = ms.lower_bound(x);
			bool flag = false;
			rep(i,k-1){
				if(itr!=ms.end())
					itr++;
				else
					flag = true;
			}
			if(flag || itr==ms.end())
				cout << -1 << endl;
			else
				cout << *itr << endl;
		}
	}
}