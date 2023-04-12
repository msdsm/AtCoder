#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int num;
int cnt[3];

int main(){
	string s;
	cin >> s;
	if(s.length()==1){
		if(atoi(s.substr(0,1).c_str())%3)
			cout << -1 << endl;
		else
			cout << 0 << endl;
		exit(0);
	}
	rep(i,s.length()){
		num+=atoi(s.substr(i,1).c_str());
		cnt[atoi(s.substr(i,1).c_str())%3]++;
	}
	num%=3;
	switch(num){
		case 0: 
		cout << 0 << endl;
		break;

		case 1:
		if(cnt[1]>0)
			cout << 1 << endl;
		else{
			if(cnt[2]>=2&&s.length()>2)
				cout << 2 << endl;
			else
				cout << -1 << endl;
		}
		break;

		case 2:
		if(cnt[2]>0)
			cout << 1 << endl;
		else{
			if(cnt[1]>=2&&s.length()>2)
				cout << 2 << endl;
			else
				cout << -1 << endl;
		}
		break;
	}
}