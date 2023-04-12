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
	ll n,l,r;
	cin >> n >> l >> r;
	vector<ll> a(n);
	cinf(a,n);
	vector<ll> b(n);
	rep(i,n)b[i]=a[i];
	ll ans = 0;
	rep(i,n)ans+=b[i];
	vector<ll> s(n);
	s[0]=a[0];
	rep2(1,i,n){
		s[i] = s[i-1]+a[i];
	}
/*
	cout << "debug start" << endl;
	rep(i,n)cout << s[i] << ' ';
	cout<<endl;
	cout << "debug end" << endl;
*/	
	
	vector<ll> x;
	ll tmp = l;
	ll mi = 0;
	
	rep(i,n){
		if(mi<s[i]-tmp){
			mi = s[i]-tmp;
			x.clear();
			x.push_back(i+1);
		}else if(mi==s[i]-tmp){
			x.push_back(i+1);
		}
		tmp += l;
	}
	s[0]=a[n-1];
	rep2(1,i,n){
		s[i] = s[i-1] + a[n-i-1];
	}
	vector<ll> y;
	mi = 0;
	tmp = r;
	rep(i,n){
		if(mi<s[i]-tmp){
			mi = s[i]-tmp;
			y.clear();
			y.push_back(i+1);
		}else if(mi==s[i]-tmp){
			y.push_back(i+1);
		}
		tmp += r;
	}
	ll idx,idy;
	s[0]=a[0];
	rep2(1,i,n){
		s[i] = s[i-1]+a[i];
	}
	if(l<=r){
		idx = x[x.size()-1];//個数
		tmp = 0;
		while(true){
			if(tmp>y.size()-1)
				break;
			if(y[tmp]+idx>=n-1)
				break;
			tmp++;
		}
		if(tmp!=0)tmp--;
		idy = y[tmp];
		tmp = l*idx + r*idy + s[n-idy-1]-s[idx-1];
		if(tmp<ans)ans=tmp;
	}else{
		idy = y[y.size()-1];//個数
		tmp = 0;
		while(true){
			if(tmp>x.size()-1)
				break;
			if(x[tmp]+idy>=n-1)
				break;
			tmp++;
		}
		if(tmp!=0)tmp--;
		idx = x[tmp];
		tmp = l*idx + r*idy + s[n-idy-1]-s[idx-1];
		if(tmp<ans)ans=tmp;
	}

	cout << "debug start" << endl;
	cout << idx << endl;
	cout << idy << endl;
	cout << "debug end" << endl;
	
	
	cout << ans << endl;
}