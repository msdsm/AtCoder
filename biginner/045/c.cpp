#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ull sum;
ll pre;

int main(){
	string s;
	cin >> s;
	rep(i,(1<<s.length()-1)){

//cout << i << ":" ;

		pre=0;
		rep(j,s.length()-1){
			if(i&(1<<j)){

//cout << s.substr(pre,j-pre+1) << "+";

				sum+=atol(s.substr(pre,j-pre+1).c_str());
				pre=j+1;
			}
		}

//cout << s.substr(pre,s.length()-pre+1) << endl;

		sum+=atol(s.substr(pre,s.length()-pre+1).c_str());
	}
	cout << sum << endl;
}