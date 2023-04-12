#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


using namespace std;

ull ans;

int main(){
	ull n;
	cin >> n;
	ull a[n];
	cinf(a,n);
	sort(a,a+n);
	rep(i,n-1){
		ans+=a[n-1-i];
	}
	cout << ans << endl;
}