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

ll tmp1,tmp2,s;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll q;
	cin >> q;
	priority_queue<ll,vector<ll>,greater<ll> > data;
	rep(i,q){
		cin >> tmp1;
		switch(tmp1){
			case 1:
			cin>>tmp2;
			data.push(tmp2-s);
			break;

			case 2:
			cin>>tmp2;
			s+=tmp2;
			break;

			case 3:
			cout << data.top() + s << endl;
			data.pop();
			break;
		}
	}
}