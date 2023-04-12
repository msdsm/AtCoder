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
	string s;
	cin >> s;
	while(!s.empty()){
//cout << s << endl;
//cout << s.length() << endl;
		if(s.substr(s.length()-3,3)=="eam"){
			if(s.substr(s.length()-5,5)!="dream"){
				cout << "NO" << endl;
				return 0;
			}
			s.erase(s.begin()+s.length()-5,s.end());
		}else if(s.substr(s.length()-3,3)=="mer"){
			if(s.substr(s.length()-7,7)!="dreamer"){
				cout << "NO" << endl;
				return 0;
			}
			s.erase(s.begin()+s.length()-7,s.end());
		}else if(s.substr(s.length()-3,3)=="ase"){
			if(s.substr(s.length()-5,5)!="erase"){
				cout << "NO" << endl;
				return 0;
			}
			s.erase(s.begin()+s.length()-5,s.end());
		}else if(s.substr(s.length()-3,3)=="ser"){
			if(s.substr(s.length()-6,6)!="eraser"){
				cout << "NO" << endl;
				return 0;
			}
			s.erase(s.begin()+s.length()-6,s.end());
		}else{
			cout << "NO" << endl;
			return 0;
		}

	}
	cout << "YES" << endl;
}