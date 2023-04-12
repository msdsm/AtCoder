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

string x;

bool f(string a, string b){
	ll l = min(a.length(),b.length());
		int i=0;
		while(a[i]==b[i]){
			i++;
			if(i==l){
				if(a.length()==l)
					return true;
				else
					return false;
			}
		}
		int an=0;
		int bn=0;
		rep(j,26){
			if(a[i]==x[j]){
				an = j;
				break;
			}
		}
		rep(j,26){
			if(b[i]==x[j]){
				bn = j;
				break;
			}
		}
		return an < bn;//aの方が辞書順ではやいときにtrue
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	cin >> x;
	ll n;
	cin >> n;
	vector<string> s(n);
	cinf(s,n);
	sort(s.begin(),s.end(),f);
	rep(i,n){
		cout << s[i] << endl;
	}
}