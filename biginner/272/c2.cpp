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
	if(n==2){
		if((a[0]+a[1])%2==1){
			cout << -1 << endl;
			return 0;
		}
	}
	vector<ll> odd,even;
	rep(i,n){
		if(a[i]%2==0)
			even.push_back(a[i]);
		else
			odd.push_back(a[i]);
	}
	sort(even.begin(),even.end());
	sort(odd.begin(),odd.end());
	ll tmp1=0;
	ll tmp2=0;
	if(even.size()>1)tmp1=even[even.size()-1]+even[even.size()-2];
	if(odd.size()>1)tmp2=odd[odd.size()-1]+odd[odd.size()-2];
	cout << max(tmp1,tmp2) << endl;
}