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

using P = pair<char,ll>;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	string s,t;
	cin >> s;
	cin >> t;
	ll i = 0;
	ll cnt = 0;
	vector<P> vs,vt;
	char c;
	while(i<t.length()){
		if(i==0){
			c = t[i];
			cnt++;
			i++;
			continue;
		}
		if(t[i]==c){
			cnt++;
		}else{
			vt.push_back(P(c,cnt));
			cnt = 1;
			c = t[i];
		}
		i++;
	}
	vt.push_back(P(c,cnt));

	cnt = 0;
	i = 0;
	while(i<s.length()){
		if(i==0){
			c = s[i];
			cnt++;
			i++;
			continue;
		}
		if(s[i]==c){
			cnt++;
		}else{
			vs.push_back(P(c,cnt));
			cnt = 1;
			c = s[i];
		}
		i++;
	}
	vs.push_back(P(c,cnt));
	/*
	cout << "debug start" << endl;
	rep(i,vs.size())cout << vs[i].fst << ' ' << vs[i].snd << endl;
	cout << "debug end" << endl;
	cout << "debug start" << endl;
	rep(i,vt.size())cout << vt[i].fst << ' ' << vt[i].snd << endl;
	cout << "debug end" << endl;
	*/
	if(vs.size()==vt.size()){
		rep(i,vs.size()){
			if(vs[i].fst!=vt[i].fst){
				cout << "No" << endl;
				return 0;
			}
			if(vs[i].snd>vt[i].snd){
				cout << "No" << endl;
				return 0;
			}
			if(vs[i].snd<vt[i].snd && vs[i].snd==1){
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}