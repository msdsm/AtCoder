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

ll f(string s){
	ll sum=0;
	ll a[9]={0};
	rep(i,s.length()){
		a[stoi(s.substr(i,1))-1]++;
	}
	rep(i,9){
		sum+=(i+1)*powl(10,a[i]);
	}
	return sum;
}

ll cnt1,cnt2;
ll cnt[9];
ll sum1,sum2;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll k;
	cin >> k;
	string s;
	cin >> s;
	string t;
	cin >> t;
	s.pop_back();
	t.pop_back();
	rep(i,4){
		cnt[stoi(s.substr(i,1))-1]++;
		cnt[stoi(t.substr(i,1))-1]++;
	}
	rep(i,9){
		cnt[i]++;
		rep(j,9){
			cnt[j]++;
			rep(l,9){
				if(cnt[l]<=k)
					continue;
				else
					goto Exit;
			}
			s += to_string(i+1);
			t += to_string(j+1);
			if(i!=j)
				cnt1+=(k-cnt[j]+1)*(k-cnt[i]+1);
			else
				cnt1+=(k-cnt[j]+1)*(k-cnt[i]+2);
			sum1 = f(s);
			sum2 = f(t);
			if(sum1>sum2){
				if(i!=j)
					cnt2+=(k-cnt[j]+1)*(k-cnt[i]+1);
				else
					cnt2+=(k-cnt[j]+1)*(k-cnt[i]+2);
/*
				cout << "debug start" << endl;
				cout << i << endl;
				cout << j << endl;
				cout << "debug end" << endl;
*/				
				
			}
			s.pop_back();
			t.pop_back();

			Exit:
			cnt[j]--;
		}
		cnt[i]--;
	}
/*
	cout << "debug start" << endl;
	cout << cnt1 << endl;
	cout << "debug end" << endl;


	cout << "debug start" << endl;
	cout << cnt2 << endl;
	cout << "debug end" << endl;
*/
	
	
	
	cout << setprecision(20) << static_cast<ld>(cnt2)/cnt1 << endl;
}