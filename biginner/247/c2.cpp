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
	vector<int> ans;
	stack<int> s;
	int n;
	cin >> n;
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	s.push(n);
	while(!s.empty()){
		int tmp = s.top();
		s.pop();
		if(tmp!=2){
			s.push(tmp-1);
			s.push(tmp);
			s.push(tmp-1);
		}else{
			ans.push_back(1);
			ans.push_back(2);
			ans.push_back(1);
			ans.push_back(tmp);
		}
	}
	rep(i,ans.size()){
		if(i!=ans.size()-1)
			cout << ans[i] << ' ';
		else
			cout << ans[i] << endl;
	}
}