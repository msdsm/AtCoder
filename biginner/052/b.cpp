#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int x,ans;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i,n){
		switch(s[i]){
			case 'I':x++;if(x>ans)ans=x;break;
			case 'D':x--;break;
		}
	}
	cout << ans << endl;
}