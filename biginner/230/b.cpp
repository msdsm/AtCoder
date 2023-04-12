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
	string s;
	cin >> s;
	int n = s.length();
	string t1,t2,t3;
	rep(i,n){
		switch(i%3){
			case 0:
			t1.push_back('o');
			t2.push_back('x');
			t3.push_back('x');
			break;

			case 1:
			t1.push_back('x');
			t2.push_back('x');
			t3.push_back('o');
			break;

			case 2:
			t1.push_back('x');
			t2.push_back('o');
			t3.push_back('x');
			break;
		}
	}
	if(s==t1 || s==t2 || s==t3)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}