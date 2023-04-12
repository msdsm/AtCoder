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
	int n;
	cin >> n;
	vector<string> s(n),t(n);
	cinf(s,n);
	rep(i,n){
		t[i]=s[i];
	}
	sort(s.begin(),s.end());
	int max = 0;
	string ans=s[0];
	int cnt=1;
	rep(i,n-1){
		if(s[i]==s[i+1]){
			cnt++;
		}else{
			if(cnt>max&&i>0){
				ans=s[i-1];
				max=cnt;
			}else{
				cnt=1;
			}
		}
	}
	//cout << cnt << endl;
	//cout << max << endl;
	if(cnt>max)
		ans=t[n-1];
	//cout << s[n-1] << endl;
	cout << ans << endl;
}