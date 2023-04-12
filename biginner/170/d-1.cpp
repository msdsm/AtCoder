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
	ll n,tmp;
	vector<ll> a;
	cin >> n;
	int equ=0;
	rep(i,n){
		cin >> tmp;
		a.push_back(tmp);
	}
	for(auto i=0;i<a.size();i++){
		for(auto j=0;j<a.size();j++){
			if(i==j)
				continue;
			if(a[i]%a[j]==0){
				if(a[i]==a[j])
					equ=1;
				a.erase(a.begin()+i);
				i--;
				break;
			}
		}
	}
	cout << a.size()-equ << endl;
}