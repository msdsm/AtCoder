#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int ans;
int cnt;
int ans_cnt;

int main(){
	int n;
	cin >> n;
	int a[n];
	cinf(a,n);
	arep(2,i,1001){
		cnt=0;
		rep(j,n){
			if(a[j]%i==0)
				cnt++;
		}
		if(ans_cnt<cnt){
			ans=i;
			ans_cnt=cnt;
		}
	}
	cout << ans << endl;
}