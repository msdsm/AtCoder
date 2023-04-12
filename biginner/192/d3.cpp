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
	string x;
	cin >> x;
	ll m;
	cin >> m;
	set<int> st;
	rep(i,x.length())st.insert(stoi(x.substr(i,1)));
	ll d = *max_element(st.begin(),st.end());
/*
	cout << "debug start" << endl;
	cout << d << endl;
	cout << "debug end" << endl;
*/	
	
	ll ng = d+1;
	ll ok = m+2;

	auto f = [&](ll n){
		ll sum = 0;

		cout << "debug start" << endl;
		cout << n << endl;
		cout << "debug end" << endl;
		
		
		rep(i,x.length()){
			if((ld)sum/m+(ld)stoi(x.substr(i,1))*powl(n,x.length()-i-1)/m>1){
				sum=2;
				break;
			}else{
				sum+=stoi(x.substr(i,1))*powl(n,x.length()-i-1);
			}

			cout << "debug start" << endl;
			cout << sum << endl;
			cout << "debug end" << endl;
			
			
		}

		cout << "debug start" << endl;
		cout << sum << endl;
		cout << "debug end" << endl;
		
		
		if(sum<=1)
			return false;
		else
			return true;
	};

	while(ok - ng > 1){
		int mid = (ng + ok) / 2;
		(f(mid) ? ok : ng) = mid;
	}

	if(ok == m+2)
		cout << 0 << endl;
	else
		cout << ok-1-d << endl;

}