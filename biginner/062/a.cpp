#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	set<int> st1{1,3,5,7,8,10,12};
	set<int> st2{4,6,9,11};
	set<int> st3{2};
	int x,y;
	cin >> x >> y;
	if(st1.count(x)==1&&st1.count(y)==1)
		cout << "Yes" << endl;
	else if(st2.count(x)==1&&st2.count(y)==1)
		cout << "Yes" << endl;
	else if(st3.count(x)==1&&st3.count(y)==1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}