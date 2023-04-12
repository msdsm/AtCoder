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
	ll n,x;
	cin >> n >> x;
	string s;
	cin >> s;
	string ans;
	while(x){
		if(x%2)
			ans.push_back('1');
		else
			ans.push_back('0');
		x/=2;
	}
	reverse(ans.begin(),ans.end());
	//cout << ans << endl;
	rep(i,n){
		switch(s[i]){
			case 'R':
			ans.push_back('1');
			break;
			case 'L':
			ans.push_back('0');
			break;
			case 'U':
			ans.pop_back();
			break;
		}
	}
	//cout << ans << endl;
	x = 0;
	rep(i,ans.size()){
		x*=2;
		x+=stoi(ans.substr(i,1));
	}
	cout << x << endl;
}