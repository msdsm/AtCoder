#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt;
ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;
	vector<ll> a(m),b(m);
	rep(i,m){
		cin >> a[i] >> b[i];
	}

	int k;
	cin >> k;

	vector<ll> c(k),d(k);
	rep(i,k){
		cin >> c[i] >> d[i];
	}

	vector<bool> data(n);
	rep(i,n){
		data[i]=false;
	}

	for(int bit=0; bit < (1<<k); bit++){
		for(int i=0; i < k; i++){
			if(bit&(1<<i)){
				data[c[i]-1]=true;
			}else{
				data[d[i]-1]=true;
			}
		}
		rep(j,m){
			if(data[a[j]-1]&&data[b[j]-1])
				cnt++;	
		}
		if(ans<cnt)
			ans = cnt;
		rep(i,n){
			data[i]=false;
		}
		cnt=0;
	}
	cout << ans << endl;
}