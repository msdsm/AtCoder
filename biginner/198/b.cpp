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

int cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	string s;
	cin >> s;
	ll n = stoi(s);
	if(n==0){
		cout << "Yes" << endl;
		return 0;
	}

	while(n%10==0){
		cnt++;
		n/=10;
	}
/*
	cout << "debug start" << endl;
	cout << cnt << endl;
	cout << "debug end" << endl;
*/	
	
	reverse(s.begin(),s.end());
	rep(i,cnt){
		s+="0";
	}
	reverse(s.begin(),s.end());
	string t = s;
	reverse(t.begin(),t.end());
	if(s==t)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}