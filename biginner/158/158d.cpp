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
	string s;
	cin >> s;
	int q;
	cin >> q;
	string t;
	rep(i,q){
		int ty;
		cin >> ty;
		if(ty==1)
			swap(s,t);
		else{
			int f;
			cin >> f;
			char c;
			cin >> c;
			if(f==1){
				t+=c;
			}else{
				s+=c;
			}
		}
	}
	reverse(t.begin(),t.end());
	cout << t+s << endl;
}