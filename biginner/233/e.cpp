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
	string s,ans;
	cin >> s;
	ll sum=0;
	rep(i,s.length()){
		sum += stoi(s.substr(i,1));
	}
	//cout << sum << endl;
	ll c = 0;
	rep(i,s.length()){
		if(i>0){
			sum -= stoi(s.substr(s.length()-i,1));
		}
		ans.push_back((sum+c)%10 + '0');
		c = (sum+c)/10;
	}
	if(c!=0){
		ans.push_back(c%10 + '0');
	}
	reverse(ans.begin(),ans.end());
	cout << ans << endl;
}