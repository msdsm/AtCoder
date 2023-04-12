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
	int a[5];
	cinf(a,5);
	set<int> st;
	map<int,int> mp;
	rep(i,5){
		st.insert(a[i]);
		mp[a[i]]++;
	}
	if(st.size()==2){
		auto itr = st.begin();
		auto itr2 = itr;
		itr2++;
		if(mp[*itr]==2 || mp[*itr]==3){
			itr++;
			if(mp[*itr]==2 || mp[*itr]==3){
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
			}
		}else{
			cout << "No" << endl;
		}
	}else{
		cout << "No" << endl;
	}
}