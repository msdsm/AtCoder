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
	vector<ll> a(n),b(n);
	cinf(a,n);
	cinf(b,n);
	ll q;
	cin >> q;
	vector<set<ll> > sta(n);
	sta[0].insert(a[0]);
	rep2(1,i,n){
		sta[i]=sta[i-1];
		sta[i].insert(a[i]);
	}
	vector<set<ll> > stb(n);
	stb[0].insert(b[0]);
	rep2(1,i,n){
		stb[i]=stb[i-1];
		stb[i].insert(b[i]);
	}
	while(q--){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		if(sta[x].size()==stb[y].size()){
			auto itr1 = sta[x].begin();
			auto itr2 = stb[y].begin();
			while(itr1!=sta[x].end()&&itr2!=stb[y].end()){
				if(*itr1!=*itr2){
					cout << "No" << endl;
					break;
				}
				itr1++;
				itr2++;
				if(itr1==sta[x].end()){
					cout << "Yes" << endl;
				}
			}
		}else{
			cout << "No" << endl;
		}
	}
}