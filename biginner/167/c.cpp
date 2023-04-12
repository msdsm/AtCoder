#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
#define INF LLONG_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool judge(const ll *algo,ll m,ll x){
	rep(i,m){
		if(algo[i]<x)
			return false;
	}
	return true;
}

int main(){
	ll n,m,x;
	cin >> n >> m >> x;
	ll c[n];
	ll a[n][m];
	ll algo[m];
	rep(i,m){
		algo[i]=0;
	}
	rep(i,n){
		cin >> c[i];
		rep(j,m){
			cin >> a[i][j];
		}
	}

	ll sum=0;
	ll min=INF;

	rep(bit,(1<<n)){
		sum=0;
		rep(i,n){
			if(bit&(1<<i)){
				sum+=c[i];
				rep(j,m){
					algo[j]+=a[i][j];
				}
			}
		}
		if(judge(algo,m,x)){
			if(min>sum)
				min=sum;
		}
		rep(j,m){
			algo[j]=0;
		}
	}
	if(min==INF)
		cout << -1 << endl;
	else
		cout << min << endl;
}