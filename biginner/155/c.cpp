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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	cin >> n;
	vector<string> s(n);
	cinf(s,n);
	multiset<string> st;
	rep(i,n){
		st.insert(s[i]);
	}
	ll max=0;
	for(auto itr=st.begin();itr!=st.end();itr++){
		//string tmp = *itr;
		if(max<st.count(*itr))
			max=st.count(*itr);
	}
	vector<string> ans;
	for(auto itr=st.begin();itr!=st.end();itr++){
		//string tmp = *itr;
		if(max==st.count(*itr))
			ans.push_back(*itr);
	}
	sort(ans.begin(),ans.end());
	set<string> st2;
	rep(i,ans.size()){
		st2.insert(ans[i]);
	}
	for(auto itr = st2.begin();itr!=st2.end();itr++){
		cout << *itr << endl;
	}
}