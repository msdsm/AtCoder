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
	ll k;
	cin >> k;
	ll rem = 7%k;
	arep(1,i,1000000){
		if(rem==0){
			cout << i << endl;
			return 0;
		}
		rem = (rem*10+7)%k;
	}
	cout << "-1" << endl;
}