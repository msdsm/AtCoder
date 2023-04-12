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
	ll n;
	cin >> n;
	vector<ll> a(n),b(n);
	cinf(a,n);cinf(b,n);
	ll q;
	cin >> q;
	vector<ll> v1,v2;
	set<ll> st;
	rep(i,n){
		if(st.count(a[i])==0){
			st.insert(a[i]);
			v1.push_back(i);
		}else{
			continue;
		}
	}
	st.clear();
	rep(i,n){
		if(st.count(b[i])==0){
			st.insert(b[i]);
			v2.push_back(i);
		}else{
			continue;
		}
	}
	vector<bool> bl(min(v1.size(),v2.size()));
	st.clear();
	set<ll> st2;
	rep(i,min(v1.size(),v2.size())){
		if(a[v1[i]]==b[v2[i]]){
			if(i>0)
				bl[i]=bl[i-1];
			else
				bl[i]=true;
		}else{
			if(st.count(b[v2[i]])>0)
				st.erase(b[v2[i]]);
			else
				st2.insert(b[v2[i]]);

			if(st2.count(a[v1[i]])>0)
				st2.erase(a[v1[i]]);
			else
				st.insert(a[v1[i]]);

			if(st.empty()&&st2.empty())
				bl[i]=true;
			else
				bl[i]=false;
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,bl.size())cout << bl[i] << ' ';cout<<endl;
	cout << "debug end" << endl;
*/	
	
	while(q--){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		ll index1 = lower_bound(v1.begin(),v1.end(),x)-v1.begin();
		ll index2 = lower_bound(v2.begin(),v2.end(),y)-v2.begin();
		if(v1[index1]>x)index1--;
		if(v2[index2]>y)index2--;
		if(index1==v1.size())index1--;
		if(index2==v2.size())index2--;
/*
		cout << "debug start" << endl;
		cout << index1 << endl;
		cout << index2 << endl;
		cout << "debug end" << endl;
*/		
		
		if(index1==index2){
			if(bl[index1])
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}else{
			cout << "No" << endl;
		}
	}
}