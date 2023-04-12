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
	if(n%2==0){
		vector<char> v;
		rep(i,n){
			v.push_back(s[i]);
			sort(v.begin(),v.end());
		}
		string a,b;
		for(int i = 0; i < n; i+=2){
			a.push_back(v[i]);
			b.push_back(v[i+1]);
		}
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		ll x = stoi(a);
		ll y = stoi(b);
		ll tmp = x*y;
		char c = a[a.length()-1];
		char c2 = b[b.length()-1];
		a.erase(a.length()-1);
		b.erase(b.length()-1);
		a.push_back(c2);
		b.push_back(c);
		x = stoi(a);
		y = stoi(b);
		ll tmp2 = x*y;
		cout << max(tmp,tmp2) << endl;
	}else{
		vector<char> v;
		rep(i,n){
			v.push_back(s[i]);
			sort(v.begin(),v.end());
		}
		string a,b;
		a.push_back(v[0]);
		for(int i = 1; i < n; i+=2){
			a.push_back(v[i]);
			b.push_back(v[i+1]);
		}

		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		ll x = stoi(a);
		ll y = stoi(b);
		ll tmp = x*y;
/*
		cout << "debug start" << endl;
		cout << tmp << endl;
		cout << "debug end" << endl;
*/
		char c = a[a.length()-1];
		a.erase(a.length()-1);
		b.push_back(c);
		x = stoi(a);
		y = stoi(b);
		ll tmp2 = x*y;
/*
		cout << "debug start" << endl;
		cout << tmp2 << endl;
		cout << "debug end" << endl;
*/		
		
		if(tmp2>tmp)
			cout << tmp2 << endl;
		else
			cout << tmp << endl;
	}
}