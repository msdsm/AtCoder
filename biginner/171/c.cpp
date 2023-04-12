#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


using namespace std;


char alpha(int x){ //0-25
	if(x==0){
		return 'z';
	}
	return static_cast<char>(96+x);
}

int main(){
	ull n;
	cin >> n;
	string name="";
	int num[15]={0};
	int i=0;
	while(n!=0){
		num[i]=n%26;
		n/=26;
		i++;
	}
	rep(j,i){
		name=alpha(num[j])+name;
	}
	cout << name << endl;
}