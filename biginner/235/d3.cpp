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

bool check[1000010];

ll digit(ll x){
	ll cnt = 0;
	while(x){
		x/=10;
		cnt++;
	}
	return cnt;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll a,n;
	cin >> a >> n;
	queue<pll> open;
	open.push(pll(n,0));
	while(!open.empty()){
		pll tmp = open.front();
		open.pop();
		check[tmp.fst]=true;
		//cout << tmp.fst << ' ' << tmp.snd << endl;
		if(tmp.fst==1){
			cout << tmp.snd << endl;
			return 0;
		}
		if(tmp.fst%a==0){
			if(!check[tmp.fst/a]){
				open.push(pll(tmp.fst/a,tmp.snd+1));
				check[tmp.fst]=true;
				//cout << pll(tmp.fst/a,tmp.snd+1).fst << ' ' << pll(tmp.fst/a,tmp.snd+1).snd << endl;
			}
		}
		ll num = tmp.fst;
		string s = to_string(num);
		//cout << s << endl;
		if(s[1]!='0'){
			ll tmp2 = num/powl(10,digit(num)-1);
			ll tmp3 = num%static_cast<ll>(powl(10,digit(num)-1));
			num = tmp2 + 10*tmp3;
			if(!check[num]){
				open.push(pll(num,tmp.snd+1));
				check[num]=true;
			}
		}
	}
	cout << -1 << endl;
}