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
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	if(n==1){
		cout << 0 << endl;
		return 0;
	}
	if(n%2==0){
		vector<ll> b(n/2);
		vector<ll> c(n/2);
		set<ll> st;
		rep(i,n/2){
			b[i]=a[i];
			c[i]=a[i+n/2];
		}
		reverse(c.begin(),c.end());
		rep(i,n/2){
			if(b[i]==c[i])
				continue;
			else{
				st.insert(b[i]);
				st.insert(c[i]);
			}
		}
/*
		cout << "debug start" << endl;
		coutf(b,n/2);
		coutf(c,n/2);
		cout << "debug start" << endl;
		for(auto itr=st.begin();itr!=st.end();itr++)cout << *itr << endl;
		cout << "debug end" << endl;
*/		
		if(st.empty())
			cout << 0 << endl;
		else
			cout << st.size()-1 << endl;
	}else{
		vector<ll> b((n-1)/2),c((n-1)/2);
		set<ll> st;
		rep(i,(n-1)/2){
			b[i]=a[i];
			c[i]=a[n-i-1];
		}
		rep(i,(n-1)/2){
			if(b[i]==c[i])
				continue;
			else{
				st.insert(b[i]);
				st.insert(c[i]);
			}
		}

/*
		cout << "debug start" << endl;
		coutf(b,n/2);
		coutf(c,n/2);
		cout << "debug start" << endl;
		for(auto itr=st.begin();itr!=st.end();itr++)cout << *itr << endl;
		cout << "debug end" << endl;
*/
 
		if(st.empty())
			cout << 0 << endl;
		else
			cout << st.size()-1 << endl;
	}
}