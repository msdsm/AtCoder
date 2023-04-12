//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt;
ll cnt2;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	srand(time(NULL));
	rep(i,1000){
		ll n;
		n = rand()%1000000+2;
	//cin >> n;
		vector<ll> a(n);
		vector<ll> b(n);
	//cinf(a,n);
		rep(i,n)a[i]=rand()%1000000000+1;
		rep(i,n)b[i]=a[i];
		rep(i,n)a[i]=a[i]%200;
		int data[200];
		rep(i,200)data[i]=0;
		rep(i,n){
			data[a[i]]++;
		}
		rep(i,200){
			cnt += data[i]*(data[i]-1)/2;
		}
	//cout << cnt << endl;
		rep(i,n){
			rep2(i+1,j,n){
				if((b[i]-b[j])%200==0)
					cnt2++;
			}
		}
		if(cnt!=cnt2){
			cout << "No" << ' ' << n << endl;
			rep(i,n)cout << b[i] << endl;
			cout << cnt << endl;
			cout << cnt2 << endl;
			return 0;
		}
	}
}