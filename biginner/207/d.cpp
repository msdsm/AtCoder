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

ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int n;
	cin >> n;
	vector<pii> s(n),t(n);
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	rep(i,n)cin >> s[i].first >> s[i].second;
	rep(i,n)cin >> t[i].first >> t[i].second;
	for(int q=-20;q<=20;q++){
		for(int r = -20;r<=20;r++){
			for(int p = 0; p < 360; p++){
				rep(i,n)s[i].first+=q;
				rep(i,n)s[i].second+=r;
				rep(i,n){
					int tmp1 = s[i].first;
					int tmp2 = s[i].second;
					if(static_cast<ld>(tmp1*cos(acos(-1)*p/180)-tmp2*sin(acos(-1)*p/180))
						==floor(tmp1*cos(acos(-1)*p/180)-tmp2*sin(acos(-1)*p/180))
						&&
						static_cast<ld>(tmp2*cos(acos(-1)*p/180)+tmp1*sin(acos(-1)*p/180))
						==floor(tmp2*cos(acos(-1)*p/180)+tmp1*sin(acos(-1)*p/180))
						){
						s[i].first=tmp1*cos(acos(-1)*p/180)-tmp2*sin(acos(-1)*p/180);
						s[i].second=tmp2*cos(acos(-1)*p/180)+tmp1*sin(acos(-1)*p/180);
					}else{
						goto Exit;
					}
				}
				sort(s.begin(),s.end());
				rep(i,n){
					if(s[i].first==t[i].first&&s[i].second==t[i].second){
						if(i==n-1)
							cnt++;
					}else{
						break;
					}
				}
				Exit:continue;
			}
		}
	}
	if(cnt>0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}