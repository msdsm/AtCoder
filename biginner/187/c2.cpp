#pragma GCC optimize("Ofast")
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin >> n;
	set<string> a,b;
	rep(i,n){
		string tmp;
		cin >> tmp;
		if(tmp[0]=='!'){
			reverse(tmp.begin(),tmp.end());
			tmp.pop_back();
			reverse(tmp.begin(),tmp.end());
			a.insert(tmp);
		}else
		b.insert(tmp);
	}
	while(!a.empty()){
		auto itr = a.begin();
		if(b.count(*itr)){
			cout << *itr << endl;
			exit(0);
		}
		a.erase(itr);
	}
	cout << "satisfiable" << endl;
}