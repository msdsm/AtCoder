#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt[51];

int main(){
	int n,m;
	cin >> n >> m;
	int tmp;
	rep(i,m){
		cin >> tmp;
		cnt[tmp-1]++;
		cin >> tmp;
		cnt[tmp-1]++;
	}
	rep(i,n){
		cout << cnt[i] << endl;
	}
}