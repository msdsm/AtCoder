#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnth[300001];
ll cntw[300001];
ll ex[300001][300001];

int main(){
	ll h,w,m;
	cin >> h >> w >> m;
	ll hh[m];
	ll ww[m];
	rep(i,m){
		cin >> hh[i] >> ww[i];
		ex[hh[i]-1][ww[i]-1]=1;
		cnth[hh[i]-1]++;
		cntw[ww[i]-1]++;
	}
	ll maxh=cnth[0];
	ll maxw=cntw[0];
	ll maxh_i=0;
	ll maxw_j=0;
	arep(1,i,h){
		if(maxh<cnth[i]){
			maxh=cnth[i];
			maxh_i=i;
		}else if(maxh==cnth[i]){
			if(ex[i])
		}
	}
	arep(1,j,w){
		if(maxw<cntw[j]){
			maxw=cntw[j];
			maxw_j=j;
		}
	}
	if(ex[maxh_i][maxw_j]==1)
		cout << maxh+maxw-1 << endl;
	else
		cout << maxh+maxw << endl;
}