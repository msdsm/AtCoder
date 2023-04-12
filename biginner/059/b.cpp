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
	string a,b;
	cin >> a >> b;
	if(a.length()>b.length()){
		cout << "GREATER" << endl;
		return 0;
	}
	else if(a.length()<b.length()){
		cout << "LESS" << endl;
		return 0;
	}
	else{
		while(!a.empty()){
			if(a[0]>b[0]){
				cout << "GREATER" << endl;
				return 0;
			}
			else if(a[0]<b[0]){
				cout << "LESS" << endl;
				return 0;
			}
			else{
				a.erase(a.begin());
				b.erase(b.begin());
			}
		}
	}
	cout << "EQUAL" << endl;
}