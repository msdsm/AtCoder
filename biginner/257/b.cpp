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
	ll n,k,q;
	cin >> n >> k >> q;
	vector<ll> a(k);
	cinf(a,k);
	vector<ll> l(q);
	cinf(l,q);
	rep(i,q)l[i]--;
	rep(i,q){
		if(a[l[i]]==n){
			continue;
		}else{
			if(l[i]==k-1){
				a[l[i]]++;
			}else if(a[l[i]+1]!=a[l[i]]+1){
				a[l[i]]++;
			}else{
				continue;
			}
		}
	}
	rep(i,k){
		cout << a[i] << ' ';
	}
	cout << endl;
}