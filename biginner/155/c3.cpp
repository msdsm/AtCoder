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

ll cnt=1;
//ll max=0;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	cin >> n;
	string s[n];
	set<string> ans[n+10];
	cinf(s,n);
	sort(s,s+n);
	ll max=0;
	rep(i,n-1){
		if(s[i]==s[i+1]){
			cnt++;
		}else{
			ans[cnt].insert(s[i]);
			if(max<cnt)
				max=cnt;
			cnt=1;
		}
		ans[cnt].insert(s[n-1]);
		if(max<cnt)
			max=cnt;
	}


// cout << "debug start" << endl;
// coutf(s,n);
// cout << "debug end" << endl;
 
 


/*
cout << "debug start" << endl;
rep(i,n){
	cout << i << " ";
	for(auto itr=ans[i].begin();itr!=ans[i].end();itr++){
		cout << *itr << ' ';
	}
	cout << " end" << endl;
}
cout << "debug end" << endl;
*/

vector<string> v;

	for(auto itr=ans[max].begin();itr!=ans[max].end();itr++){
		v.push_back(*itr);
	}
	sort(v.begin(),v.end());
	coutf(v,v.size());
}