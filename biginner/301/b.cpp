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
	vector<ll> a(n);
	cinf(a,n);
	rep2(1,i,n){
		if(abs(a[i]-a[i-1])==1){
			cout << a[i-1] << ' ';
		}else{
			if(a[i-1]<a[i]){
				cout << a[i-1] << ' ';
				rep(j,a[i]-a[i-1]-1){
					cout << a[i-1]+j+1 << ' ';
				}
			}else{
				cout << a[i-1] << ' ';
				rep(j,a[i-1]-a[i]-1){
					cout << a[i-1]-j-1 << ' ';
				}
			}
		}
	}
	cout << a[n-1] << endl;
}