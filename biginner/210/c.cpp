//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
#define fst first
#define snd second
#define pcin(x,n) for(ll i=0;i<(n);i++)cin>>x[i].fst>>x[i].snd;
#define pdebug(x) cout << '(' << x.fst << ',' << x.snd << ")\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll tmp;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,k;
	cin >> n >> k;
	vector<ll> c(n);
	multiset<ll> st;
	set<ll> st2;
	cinf(c,n);
	ll max = 0;
	rep(i,k){
		st.insert(c[i]);
		st2.insert(c[i]);
	}
	max = st2.size();
/*	
	cout << "debug start" << endl;
	cout << max << endl;
	cout << "debug end" << endl;
*/
	tmp = max;
	rep2(1,i,n-k+1){
/*
		cout << "debug start" << endl;
		for(auto itr=st.begin();itr!=st.end();itr++)
			cout << *itr << ' ';
		cout << endl;
		cout << "debug end" << endl;
*/		
		
		st.erase(st.find(c[i-1]));
/*
		cout << "debug start" << endl;
		for(auto itr=st.begin();itr!=st.end();itr++)
			cout << *itr << ' ';
		cout << endl;
		cout << "debug end" << endl;
*/
		if(st.find(c[i-1])==st.end())
			tmp -= 1;
		if(st.find(c[i+k-1])==st.end())
			tmp += 1;
		st.insert(c[i+k-1]);
		if(max<tmp)max=tmp;
/*
		cout << "debug start" << endl;
		cout << tmp << endl;
		cout << "debug end" << endl;
*/		
		
	}
	cout << max << endl;
}