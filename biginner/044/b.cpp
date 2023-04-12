#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int alpha[26];

int main(){
	string s;
	cin >> s;
	rep(i,s.length()){
		alpha[s[i]-'a']++;
	}

	rep(i,26){
		if(alpha[i]%2==1){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}