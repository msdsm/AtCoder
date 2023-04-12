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
	vector<string> s(n);
	cinf(s,n);
	set<char> st1;
	st1.insert('H');
	st1.insert('D');
	st1.insert('C');
	st1.insert('S');

	set<char> st2;
	st2.insert('A');
	st2.insert('2');
	st2.insert('3');
	st2.insert('4');
	st2.insert('5');
	st2.insert('6');
	st2.insert('7');
	st2.insert('8');
	st2.insert('9');
	st2.insert('T');
	st2.insert('J');
	st2.insert('Q');
	st2.insert('K');

	set<string> st;
	rep(i,n){
		st.insert(s[i]);
		if(st1.count(s[i][0])==0){
			cout << "No" << endl;
			return 0;
		}
		if(st2.count(s[i][1])==0){
			cout << "No" << endl;
			return 0;
		}
	}
	if(st.size()==n)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}