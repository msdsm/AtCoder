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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	/*
	multiset<ll> st;
	st.insert(1);
	st.insert(2);
	st.insert(3);
	st.insert(4);
	st.insert(5);
	auto itr = st.begin();
	cout << *itr << endl;
	itr++;
	cout << *itr << endl;
	st.insert(6);
	cout << *itr << endl;
	st.insert(0);
	cout << *itr << endl;
	for(itr = st.begin();itr!=st.end();itr++){
		cout << *itr << endl;
	}
	st.insert(6);
	for(itr = st.begin();itr!=st.end();itr++){
		cout << *itr << endl;
	}
	auto itr2 = st.end();
	itr2--;
	st.erase(itr2);
	for(itr = st.begin();itr!=st.end();itr++){
		cout << *itr << endl;
	}
	*/

	ll n,m,k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	cinf(a,n);
	if(m==1){
		rep(i,n)cout<<a[i]<<' ';
		cout<<endl;
		return 0;
	}
	multiset<ll> ms;
	ll sum = 0;
	rep(i,m){
		ms.insert(a[i]);
	}
	auto itr = ms.begin();
	//cout << 'c' << endl;
	rep(i,k-1)itr++;
	//cout << *itr << endl;
	auto tmp = ms.begin();
	//cout << (tmp!=itr) << endl;
	while(tmp!=itr){
		//cout << 111 << endl;
		sum += *tmp;
		tmp++;
	}
	//cout << 11111 << endl;
	//cout << sum << endl;
	//cout << *tmp << endl;
	sum += (*tmp);
	cout << sum << ' ';//cout<<endl;

	rep(i,n-m){
		//a[m+i]:in  a[i]:out
		if(a[i]<(*itr)){
			sum -= a[i];
			itr++;
			sum += (*itr);
			auto tmp = ms.lower_bound(a[i]);
			ms.erase(tmp);
		}else if(a[i]>(*itr)){
			ms.erase(ms.lower_bound(a[i]));
		}else{//a[i]==(*itr)
			auto tmp = itr;
			tmp++;
			if(a[i]==(*tmp)){
				ms.erase(tmp);
			}else{
				sum += (*tmp) - (*itr);
				ms.erase(itr);
				itr = tmp;
			}
		}

		if(a[i+m]<(*itr)){
			ms.insert(a[i+m]);
			sum += a[i+m];
			sum -= (*itr);
			itr--;
		}else if(a[i+m]>(*itr)){
			ms.insert(a[i+m]);
		}else{
			ms.insert(a[i+m]);
		}
		cout << sum << ' ';
	}cout<<endl;
}