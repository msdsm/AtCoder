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
	string s;
	string t;
	cin >> s;
	cin >> t;
	ll left=0;//最初空の時yes
	rep(i,t.length()){
		if(t[i]==s[i]){
			left++;
		}else if(t[i]=='?'){
			left++;
		}else if(s[i]=='?'){
			left++;
		}else{
			break;
		}
	}
	ll right = t.length();
	ll ti = t.length();
	ll si = s.length();
	rep(i,t.length()){
		si--;
		ti--;
		if(t[ti]==s[si]){
			right--;
		}else if(t[ti]=='?'){
			right--;
		}else if(s[si]=='?'){
			right--;
		}else{
			break;
		}
	}
	vector<bool> ans(t.length()+1);
	rep(i,t.length()+1){
		if(i<=left&&right<=i)
			ans[i]=true;
		else
			ans[i]=false;
	}
	rep(i,ans.size()){
		if(ans[i])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}