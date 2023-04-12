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
	pair<string,int> p[7];
	p[0] = pair<string,int>("SUN",7);
	p[1] = pair<string,int>("MON",6);
	p[2] = pair<string,int>("TUE",5);
	p[3] = pair<string,int>("WED",4);
	p[4] = pair<string,int>("THU",3);
	p[5] = pair<string,int>("FRI",2);
	p[6] = pair<string,int>("SAT",1);
	string s;
	cin >> s;
	rep(i,7){
		if(p[i].first==s)
			cout << p[i].second << endl;
	}
}