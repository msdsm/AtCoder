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
	pll p1,p2;
	cin >> p1.fst >> p1.snd >> p2.fst >> p2.snd;
	set<pll> st;
	st.insert(pll(p1.fst+2,p1.snd+1));
	st.insert(pll(p1.fst+1,p1.snd+2));
	st.insert(pll(p1.fst-1,p1.snd+2));
	st.insert(pll(p1.fst-2,p1.snd+1));
	st.insert(pll(p1.fst-2,p1.snd-1));
	st.insert(pll(p1.fst-1,p1.snd-2));
	st.insert(pll(p1.fst+1,p1.snd-2));
	st.insert(pll(p1.fst+2,p1.snd-1));

	st.insert(pll(p2.fst+2,p2.snd+1));
	st.insert(pll(p2.fst+1,p2.snd+2));
	st.insert(pll(p2.fst-1,p2.snd+2));
	st.insert(pll(p2.fst-2,p2.snd+1));
	st.insert(pll(p2.fst-2,p2.snd-1));
	st.insert(pll(p2.fst-1,p2.snd-2));
	st.insert(pll(p2.fst+1,p2.snd-2));
	st.insert(pll(p2.fst+2,p2.snd-1));
	if(st.size()<16)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}