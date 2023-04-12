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

ll ans = numeric_limits<ll>::max();

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,a,b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	deque<char> dq;
	rep(i,s.length())dq.push_back(s[i]);
	ll cnt_a = 0;
	rep(i,s.length()){
		cnt_a = i;
		if(i!=0){
			char tmp = dq.front();
			dq.pop_front();
			dq.push_back(tmp);
		}
		ll cnt_b = 0;
		rep(i,s.length()/2){
			if(dq[i]!=dq[n-i-1])
				cnt_b++;
		}
		if(ans>cnt_b*b+cnt_a*a)
			ans=cnt_b*b+cnt_a*a;
	}
	cout << ans << endl;
}