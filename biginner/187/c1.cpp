#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll j,k;

int main(){
	ll n;
	cin >> n;
	string s[n],t[n];
	rep(i,n){
		string tmp;
		cin >> tmp;
		if(tmp[0]=='!'){
			reverse(tmp.begin(),tmp.end());
			tmp.pop_back();
			reverse(tmp.begin(),tmp.end());
			s[j]=tmp;
			j++;
		}
		else{
			t[k]=tmp;
			k++;
		}
	}

//coutf(s,j);
//coutf(t,k);

	rep(i,j){
		rep(l,k){
			if(s[i]==t[l]){
				cout << s[i] << endl;
				exit(0);
			}
		}
	}
	cout << "satisfiable" << endl;
}