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
	queue<ll> a;
	multiset<ll> b;
	rep(i,q){
		int c;
		cin >> c;
		if(c==1){
			ll x;
			cin >> x;
			a.push(x);
			b.insert(x);
		}else if(c==2){
			ll tmp = a.front();
			cout << tmp << endl;
			a.pop();
			auto itr = b.find(tmp);
			b.erase(itr);
		}else{
			while(!a.empty())
				a.pop();
			for(auto itr = b.begin();itr!=b.end();itr++){
				a.push(*itr);
			}
		}
	}
}