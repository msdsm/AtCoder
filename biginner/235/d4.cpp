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
	ll a,n;
	cin >> a >> n;
	queue<pll> open;
	vector<pll> closed;
	vector<bool> check(1000010);
	open.push(pll(1,0));
	while(!open.empty()){
		pll tmp = open.front();
		open.pop();
		closed.push_back(tmp);
		if(tmp.fst==n){
			cout << tmp.snd << endl;
			return 0;
		}
		if(!check[tmp.fst])
			check[tmp.fst]=true;
		if(tmp.fst*a<1000000 && !check[tmp.fst*a]){
			check[tmp.fst*a]=true;
			open.push(pll(tmp.fst*a,tmp.snd+1));
		}
		if(tmp.fst>=10 && tmp.fst%10!=0){
			string s = to_string(tmp.fst);
			string t;
			t.push_back(s[s.length()-1]);
			s.erase(s.end()-1);
			t += s;
			ll num = stoi(t);
			if(!check[num]){
				check[num]=true;
				open.push(pll(num,tmp.snd+1));
			}
		}
	}
	cout << -1 << endl;
}