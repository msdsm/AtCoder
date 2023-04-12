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
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n),b(n);
	cinf(a,n);
	cinf(b,n);
	ll pre1 = a[0];
	ll pre2 = b[0];
	rep2(1,i,n){
		ll tmp1=-1,tmp2=-1;
		if(pre1==-1 && pre2==-1){
			cout << "No" << endl;
			return 0;
		}
		if(pre1!=-1){
			if(abs(a[i]-pre1)<=k)
				tmp1=a[i];
			if(abs(b[i]-pre1)<=k)
				tmp2=b[i];
		}
		if(pre2!=-1){
			if(abs(a[i]-pre2)<=k)
				tmp1=a[i];
			if(abs(b[i]-pre2)<=k)
				tmp2=b[i];
		}
		pre1=tmp1;
		pre2=tmp2;
	}
	if(pre1==-1 && pre2==-1)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}