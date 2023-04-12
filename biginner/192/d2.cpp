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

double iPow (    // n乗の計算をする関数
    double base  // (base) の (power) 乗の近似値を求める
   ,int    power // べきは整数
   ) {
	double buff=1;
	do {
		if ( power & 1 ) buff*= base;
		power>>= 1;
		base*= base;
	} while ( power );
	return buff;
}

double calcNthRoot ( // n乗根の計算をする関数
    ld base  // (base) の (1/order) 乗の近似値を求める
   ,ll    order //
   ,double PREC  // 収束の精度
   ){
	double root=base ,rootPrev;
	do {
		rootPrev= root;
		root=((order-1)*root)/order + base/(order*iPow(root,order-1));
	} while ( (rootPrev-root)/root > PREC );
	return root;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	string x;
	ll m;
	cin >> x;
	cin >> m;
	ll tmp,max=0;
	rep(i,x.length()){
		tmp = stoi(x.substr(i,1));
		if(max<tmp)
			max = tmp;
	}
	ll n = x.length();
	ll d = calcNthRoot(static_cast<ld>(m),n-1,1.e-10);

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
	goto final;

	Exit:
	while(true){
		d--;
		rep(i,x.length()){
			rep(j,x.length()-i-1){
				if(tmp<=static_cast<ld>(m)/d)
					tmp*=d;
				else
					goto Exit2;
			}
			if(static_cast<ld>(sum)/stoi(x.substr(i,1))+tmp<=static_cast<ld>(m)/stoi(x.substr(i,1)))
				sum += tmp*stoi(x.substr(i,1));
			else
				goto Exit2;
			tmp=1;
		}
		goto final;

		Exit2:
		sum=0;
	}
	final:
	cout << d-max-1 << endl;
}