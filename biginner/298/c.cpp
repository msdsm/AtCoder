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
	ll n;
	cin >> n;
	ll q;
	cin >> q;
	vector<multiset<ll> > v(n);//箱から数字
	vector<set<ll> >  inv(200010);//数字から箱
	while(q--){
		int t;
		cin >> t;
		if(t==1){
			ll i,j;
			cin >> i >> j;
			j--;
			v[j].insert(i);
			j++;
			inv[i].insert(j);
		}else if(t==2){
			ll i;
			cin >> i;
			i--;
			for(auto itr=v[i].begin();itr!=v[i].end();itr++){
				cout << (*itr) << ' ';
			}cout<<endl;
		}else{
			ll i;
			cin >> i;
			for(auto itr=inv[i].begin();itr!=inv[i].end();itr++){
				cout << (*itr) << ' ';
			}cout<<endl;
		}
	}
}