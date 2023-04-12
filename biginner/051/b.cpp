#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt[3];

int main(){
	ll k,s;
	cin >> k >> s;

	//x<y<z  6倍
	rep(x,k+1){
		arep(x+1,y,k+1){
			arep(y+1,z,k+1){
				if(x+y+z==s)
					cnt[0]++;
			}
		}
	}


	//x=y<z  3倍
	rep(x,k+1){
		arep(x+1,z,k+1){
			if(x+x+z==s)
				cnt[1]++;
		}
	}


	//x<y=z  3倍
	rep(x,k+1){
		arep(x+1,y,k+1){
			if(x+y+y==s)
				cnt[2]++;
		}
	}


	//x=y=z  1倍
	rep(x,k+1){
		if(x+x+x==s)
			cnt[3]++;
	}

	cout << cnt[0]*6+cnt[1]*3+cnt[2]*3+cnt[3] << endl;
}