#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	string s,t;
	cin >> s;
	cin >> t;
	int min=t.length();
	int cnt;
	rep(i,s.length()-t.length()+1){
		//if(t.length()+i>s.length())break;
		cnt=0;
		rep(j,t.length()){
			if(t[j]!=s[i+j])cnt++;
		}
		//cout << cnt << endl;
		if(cnt<min)min=cnt;
	}
	cout << min << endl;
}