#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int i,j;
bool flagi,flagj;
int cnt;

int main(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	i = 0;
	j = n-1;
	while(i<j){
		if(s[i]=='R')
			i++;
		if(s[i]=='W')
			flagi=true;
		if(s[j]=='W')
			j--;
		if(s[j]=='R')
			flagj=true;
		if(flagj&&flagi){
			flagi=false;
			flagj=false;
			cnt++;
			i++;
			j--;
		}
	}
	cout << cnt << endl;
}
