//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll tmp2=-1;


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	cin >> n;
	set<ll> st;

	arep(1,i,n){
		string s = to_string(n);
		string b = s[0];
		string e = s[s.length()-1];
		ll num = 0;
		string c = "";
		while(num<=n){
			string tmp = e+c+b;
			num = stoi(tmp)
			if(num<=n){
				st.insert(min(i,num));
			}
			tmp2=stoi(c);
			tmp2++;
			if(tmp2>0&&to_string(tmp2).length()!=to_string(tmp2-1).length()){
				c="";
				rep(i,to_string(tmp2).length())c+="0";
			}else if(c[0]=="0"){

			}else{
				c = to_string(tmp2);
			}
		}
	}
	cout << st.size() << endl;
}