//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll sum;
ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	string x;
	ll m;
	cin >> x;
	cin >> m;
	ll tmp,max=0;
	if(x.length()==1){
		if(stoi(x)<=m)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	rep(i,x.length()){
		tmp = stoi(x.substr(i,1));
		if(max<tmp)
			max = tmp;
	}
	ll d = max;
	tmp=1;
	while(true){
/*
		cout << "debug start" << endl;
		cout << d << endl;
		cout << "debug end" << endl;
*/		
		
		d++;
		rep(i,x.length()){
			rep(j,x.length()-i-1){
				if(tmp<=static_cast<ld>(m)/d)
					tmp*=d;
				else
					goto Exit;
			}
			if(static_cast<ld>(sum)/stoi(x.substr(i,1))+tmp<=static_cast<ld>(m)/stoi(x.substr(i,1)))
				sum += tmp*stoi(x.substr(i,1));
			else
				goto Exit;
			tmp=1;
		}
/*
		cout << "debug start" << endl;
		cout << sum << endl;
		cout << "debug end" << endl;
*/
		
		if(sum<=m)
			cnt++;
		else
			break;
		tmp=1;
		sum=0;
	}
	Exit:
	cout << cnt << endl;
}