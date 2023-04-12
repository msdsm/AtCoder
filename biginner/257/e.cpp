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

bool compareoriginal(pll a, pll b){
	if(a.fst!=b.fst)
		return a.fst < b.fst;
	else
		return a.snd > b.snd;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<ll> c(9);
	cinf(c,9);
	vector<pll> cc(9);
	rep(i,9){
		cc[i].fst = c[i];
		cc[i].snd = i;
	}
	sort(cc.begin(),cc.end(),compareoriginal);
	reverse(cc.begin(),cc.end());
	//cout << cc[1].fst << endl;
	//cout << cc[1].snd << endl;
	ll sum  = n;
	ll index = 8;
	while(sum){
		while(index>=0){
			if(sum>=cc[index].fst)
				break;
			index--;
		}
		if(index<0)break;
		sum -= cc[index].fst;
		cout <<cc[index].snd+1;
	}
	cout << endl;
}