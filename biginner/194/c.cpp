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

ll sum;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	vector<ll> s1(n-1);
	vector<ll> s2(n-1);
	s1[0]=a[0];
	s2[0]=a[0]*a[0];
	arep(1,i,n-1){
		s1[i]+=s1[i-1]+a[i];
		s2[i]+=s2[i-1]+a[i]*a[i];
	}
/*
	cout << "debug start" << endl;
	coutf(s1,n-1);
	cout << "debug end" << endl;

	cout << "debug start" << endl;
	coutf(s2,n-1);
	cout << "debug end" << endl;
*/	
	
	
	
	arep(1,i,n){
/*
		cout << "debug start" << endl;
		cout << i*a[i] << endl;
		cout << 2*a[i]*s1[i-1] << endl;
		cout << s2[i-1] << endl;
		cout << "debug end" << endl;
*/		
		
		ll tmp = i*a[i]*a[i] - 2*a[i]*s1[i-1] + s2[i-1];
		sum+=tmp;

/*
		cout << "debug start" << endl;
		cout << sum << endl;
		cout << "debug end" << endl;
*/
	}
	cout << sum << endl;
}