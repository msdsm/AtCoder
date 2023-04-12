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
	int h,w;
	cin >> h >> w;
	vector<string> s(h);
	cinf(s,h);
	int a,b,c,d;
	bool flag=false;
	rep(i,h){
		rep(j,w){
			if(s[i][j]=='o'){
				if(flag){
					a = i;
					b = j;
				}else{
					c = i;
					d = j;
					flag = true;
				}
			}else{
				continue;
			}
		}
	}
	cout << abs(a-c)+abs(b-d) << endl;
}