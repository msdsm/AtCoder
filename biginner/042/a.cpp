#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int cnt;

int main(){
	int tmp;
	rep(i,3){
		cin >> tmp;
		if(tmp==5)
			cnt++;
		else if(tmp==7)
			cnt+=10;
	}
	if(cnt==12)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}