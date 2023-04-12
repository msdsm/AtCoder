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
ll max_cnt;
ll max_num;

int main(){
	ll n;
	cin >> n;
	arep(1,i,n+1){
		cnt=0;
		ll j=i;
		while(j%2==0){
			cnt++;
			j/=2;
		}
		if(cnt>=max_cnt){
			max_cnt=cnt;
			max_num=i;
		}
	}
	cout << max_num << endl;
}