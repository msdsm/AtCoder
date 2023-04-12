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

ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int h,w,x,y;
	cin >> h >> w >> x >> y;
	vector<string> s(h);
	cinf(s,h);
	rep(i,w){
		if(i<y-1){
			rep2(i,j,y-1){
				if(s[x-1][j]=='#')
					break;
				if(j==y-2)
					ans++;
			}
		}else if(i==y-1){
			ans+=1;
		}else{
			rep2(y,j,i+1){
				if(s[x-1][j]=='#')
					break;
				if(j==i)
					ans++;
			}
		}
	}
/*
cout << "debug start" << endl;
cout << ans << endl;
cout << "debug end" << endl;
*/

	rep(i,h){
		if(i<x-1){
			rep2(i,j,x-1){
				if(s[j][y-1]=='#')
					break;
				if(j==x-2)
					ans++;
			}
		}else if(i==x-1){
			continue;
		}else{
			rep2(x,j,i+1){
				if(s[j][y-1]=='#')
					break;
				if(j==i)
					ans++;
			}
		}
	}
	cout << ans << endl;
}