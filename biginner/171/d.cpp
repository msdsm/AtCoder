#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	ll n;
	cin >> n;
	ll a[n];
	cinf(a,n);
	sort(a,a+n);
	ll q;
	cin >> q;
	ull b[q],c[q],s[q];
	rep(i,q){
		cin >> b[i] >> c[i];
		s[i]=0;
	}
	ull sum;
	ll j;
	rep(i,q){
		j=0;
		while(a[j]<=b[i]){
			if(a[j]==b[i])
				a[j]=c[i];
			j++;
		}
		sum=0;
		rep(i,n){
			sum+=a[i];
		}
		cout << sum << endl;
	}
}