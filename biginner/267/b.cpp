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
	vector<int> v;
	string s;
	cin >> s;
	if(s[0]=='1'){
		cout << "No" << endl;
		return 0;
	}
	if(s[1]=='1')
		v.push_back(2);
	if(s[2]=='1')
		v.push_back(4);
	if(s[3]=='1')
		v.push_back(1);
	if(s[4]=='1')
		v.push_back(3);
	if(s[5]=='1')
		v.push_back(5);
	if(s[6]=='1')
		v.push_back(0);
	if(s[7]=='1')
		v.push_back(2);
	if(s[8]=='1')
		v.push_back(4);
	if(s[9]=='1')
		v.push_back(6);
	set<int> st;
	rep(i,v.size())st.insert(v[i]);
	if(st.size()>=2){
		v.clear();
		for(auto itr=st.begin();itr!=st.end();itr++)
			v.push_back(*itr);
		rep(i,v.size()-1){
			if(v[i]+1<v[i+1]){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}