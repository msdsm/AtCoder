#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool bl[1000001];  //falseで初期化

int main(){
	ll n,ans=0;
	cin >> n;
	ll a[n];
	cinf(a,n);
	sort(a,a+n);
	ll max=a[n-1]+1;
	ll cnt[max];
	rep(i,max){
		cnt[i]=0;
	}

	rep(i,n){
		cnt[a[i]]++;
	}

	rep(i,n){
		bl[a[i]]=true;
	}

	arep(1,i,max){
		if(bl[i]&&cnt[i]==1)
			ans++;
		if(bl[i])
			for(ll j=i;j<max;j+=i){
				bl[j]=false;
			}
	}

	cout << ans << endl;
}