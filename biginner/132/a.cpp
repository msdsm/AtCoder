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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	string s;
	cin >> s;
	multiset<char> ms;
	set<char> st;
	rep(i,s.length()){
		ms.insert(s[i]);
		st.insert(s[i]);
	}
	auto itr1 = st.begin();
	auto itr2 = st.end();
	itr2--;


	if(st.size()==2 && ms.count(*itr1)==2 && ms.count(*itr2)==2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}