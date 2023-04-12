#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

void set_zero(ull *a,ull num){
	for(ull i=0;i<num;i++){
		a[i]=0;
	}
}

ull cal(ull *num,ull x){
	ull cnt=0;
	while(*num % x == 0){
		*num /= x;
		cnt++;
	}
	return cnt;
}

int main(){
	ull n;
	cin >> n;
	ull consn = n;
	ull num = static_cast<ull>(sqrt(n));
	ull p[num];
	ull e[num];
	ull debug[num];
	set_zero(p,num);
	set_zero(e,num);
	ull a=2;
	ull j=0;
	ull t;
	ull debu=0;
	while(consn>=a*a){
		debug[debu++]=1;
		if((t=cal(&n,a))!=0){
			p[j]=a;
			e[j]=t;
			j++;
		}
		if(a==2){
			a++;
			continue;
		}
		if(a%2!=0){
			a+=2;
		}
	}

	ull count=0;
	for(ull i=0;i<num;i++){
		if(p[i]==0)
			break;
		j=1;
		ull tmp = e[i];
		while(tmp>=j){
			tmp-=j;
			count++;
			j++;
		}
	}
	rep(i,num){
		cout << p[i] << " ";
	}
	cout << endl;
	rep(i,num){
		cout << e[i] << " ";
	}
	cout << endl;
	rep(i,num){
		cout << debug[i] << " ";
	}
	cout << endl;
	cout << count << endl;
}