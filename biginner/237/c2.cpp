#pragma GCC optimize("Ofast")
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

ll cnt1,cnt2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	string s;
	cin >> s;
	ll left = 0;
	ll right = s.length()-1;
	while(s[left]=='a'){
		left++;
		cnt1++;
	}
	while(s[right]=='a'){
		right--;
		cnt2++;
	}
	string t;
	rep2(left,i,right+1){
		t.push_back(s[i]);
	}
/*
	cout << "debug start" << endl;
	cout << t << endl;
	cout << "debug end" << endl;
	*/
	string tmp = t;
	reverse(tmp.begin(),tmp.end());
	if(t==tmp && cnt1<=cnt2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}