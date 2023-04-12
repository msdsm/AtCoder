#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt[4];

int main(){
	ll n;
	cin >> n;
	string s[n];
	cinf(s,n);
	rep(i,n){
		if(s[i][0]=='A')
			cnt[0]++;
		else if(s[i][0]=='W')
			cnt[1]++;
		else if(s[i][0]=='T')
			cnt[2]++;
		else
			cnt[3]++;
	}
	cout << "AC x " << cnt[0] << endl;
	cout << "WA x " << cnt[1] << endl;
	cout << "TLE x " << cnt[2] << endl;
	cout << "RE x " << cnt[3] << endl;
}