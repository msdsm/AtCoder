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
	vector<char> s(3),t(3);
	cinf(s,3);
	cinf(t,3);
	vector<int> s2(3),t2(3);
	rep(i,3){
		if(s[i]=='R')
			s2[i]=1;
		else if(s[i]=='G')
			s2[i]=2;
		else
			s2[i]=3;

		if(t[i]=='R')
			t2[i]=1;
		else if(t[i]=='G')
			t2[i]=2;
		else
			t2[i]=3;
	}
	int cnt1=0;
	int cnt2=0;
	rep(i,3-1){
		for(ll j = 3-1; j > i; j--){
			if(s2[j]<s2[j-1]){
				int tmp = s2[j];
				s2[j] = s2[j-1];
				s2[j-1]=tmp;
				cnt1++;
			}
			if(t2[j]<t2[j-1]){
				int tmp = t2[j];
				t2[j] = t2[j-1];
				t2[j-1]=tmp;
				cnt2++;
			}
		}
	}
	//cout << cnt1 << endl;
	//cout << cnt2 << endl;
	if(cnt1%2 == cnt2%2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}