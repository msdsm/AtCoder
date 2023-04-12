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

bool f(int a,int b,int c){
	if(b==max(a,max(b,c))||b==min(a,min(b,c)))
		return false;
	return true;
}

int cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int n;
	cin >> n;
	vector<int> p(n);
	cinf(p,n);
	rep(i,n-2){
		if(f(p[i],p[i+1],p[i+2]))
			cnt++;
	}
	cout << cnt << endl;
}