#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

void reset(char *str,ll num){
	rep(i,num){
		str[i]='\0';
	}
}

ll count(const char *str,ll num,ll prime){
	ll count=0;
	char tmp_str[num];
	rep(i,num){
		rep(j,num-i){
			reset(tmp_str,num);
			rep(k,j+1){
				tmp_str[k]=str[i+k];
			}
			long tmp = atol(tmp_str);
			if(tmp%prime==0)
				count++;
		}
	}
	return count;
}

int main(){
	ll n,p;
	cin >> n >> p;
	char s[n];
	cin >> s;
	cout << count(s,n,p) << endl;
}