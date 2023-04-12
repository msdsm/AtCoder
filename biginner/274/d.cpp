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
	ll n,x,y;
	cin >> n >> x >> y;
	vector<ll> a(n);
	vector<ll> ax,ay;
	cinf(a,n);
	rep(i,n){
		if(i%2==0)
			ax.push_back(a[i]);
		else
			ay.push_back(a[i]);
	}
	set<ll> pre;
	set<ll> next;
	next.insert(ax[0]);
	rep2(1,i,ax.size()){
		pre = next;
		next.clear();
		for(auto itr=pre.begin();itr!=pre.end();itr++){
			next.insert((*itr) + ax[i]);
			next.insert((*itr) - ax[i]);
		}
	}
	if(next.count(x)==0){
		cout << "No" << endl;
		return 0;
	}
	pre.clear();
	next.clear();
	next.insert(ay[0]);
	next.insert(-ay[0]);
	rep2(1,i,ay.size()){
		pre = next;
		next.clear();
		for(auto itr=pre.begin();itr!=pre.end();itr++){
			next.insert((*itr) + ay[i]);
			next.insert((*itr) - ay[i]);
		}
	}
	if(next.count(y)==0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}