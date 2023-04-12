#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

void set_zero(ll *a,ll n){
	rep(i,n){
		a[i]=0;
	}
}

void set_flag(const ll *a,const ll *b,ll *flag,ll m,ll key,ll count){
	if(count==m){
		return;
	}else{
		int tmp1,tmp2=0;
		rep(i,m){
			if(a[i]==key&&flag[b[i]-1]==0){
				flag[b[i]-1]=key;
				if(tmp1==0)
					tmp1=b[i];
			}
			else if(b[i]==key&&flag[a[i]-1]==0){
				flag[a[i]-1]=key;
				if(tmp2==0)
					tmp2=a[i];
			}
		}
		if(tmp1>0)
			set_flag(a,b,flag,m,tmp1,count+1);
		else if(tmp2>0)
			set_flag(a,b,flag,m,tmp2,count+1);
		else
			set_flag(a,b,flag,m,key+1,count+1);
	}
}

bool judge(ll *a,ll n){
	for(int i=1;i<n;i++){
		if(a[i]==0)
			return false;
	}
	return true;
}

int main(){
	ll n,m;
	cin >> n >> m;
	ll a[m],b[m];
	rep(i,m){
		cin >> a[i] >> b[i];
	}
	ll flag[n];
	set_zero(flag,n);
	flag[0]=1;
	set_flag(a,b,flag,m,1,0);
	if(judge(flag,n)==false)
		cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		for(int i=1;i<n;i++){
			cout << flag[i] << endl;
		}
	}
}
