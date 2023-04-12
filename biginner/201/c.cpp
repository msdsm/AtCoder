//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	string s;
	cin >> s;
	set<string> st1,st2;
	rep(i,s.length()){
		if(s[i]=='o')
			st1.insert(to_string(i));
		if(s[i]=='x')
			st2.insert(to_string(i));
	}
	ll tmp=0;
	while(tmp<10000){
		string t = to_string(tmp);
		if(t.length()<4){
			int k=4-t.length();
			rep(i,k){
				t.push_back('0');
			}
			reverse(t.begin(),t.end());
		}
		for(auto itr=st1.begin();itr!=st1.end();itr++){
			rep(i,t.length()){
				if(t.substr(i,1)==(*itr)){
					goto Exit;
				}
			}
			goto Exit2;
			Exit:;
		}
		for(auto itr=st2.begin();itr!=st2.end();itr++){
			rep(i,t.length()){
				if(t.substr(i,1)==(*itr))
					goto Exit2;
			}
		}
		cnt++;

		Exit2:
		tmp++;
	}
	cout << cnt << endl;
}