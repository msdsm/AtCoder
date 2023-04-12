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
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	cinf(a,n);
	sort(a.begin(),a.end());
	bool flag = true;//全部繋がるか
	rep2(1,i,n){
		if(a[i]==a[i-1]||a[i]==a[i-1]+1)
			continue;
		else{
			flag = false;
			break;
		}
	}
	bool con;//nと0が繋がるか
	if(a[0]==a[n-1]||a[0]==(a[n-1]+1)%m)
		con = true;
	else
		con = false;

	if(con&&flag){
		cout << 0 << endl;
		return 0;
	}
	vector<ll> b;
	rep(i,n){
		b.push_back(a[i]);
	}
	rep(i,n){
		b.push_back(a[i]);
	}

/*
	cout << "debug start" << endl;
	rep(i,n)cout<<a[i]<< ' ';
	cout<<endl;
	cout << "debug end" << endl;


	cout << "debug start" << endl;
	rep(i,b.size())cout<<b[i]<<' ';
	cout<<endl;
	cout << "debug end" << endl;
*/	
	
	
	

	ll sum = 0;
	ll tmp = b[0];
	rep2(1,i,b.size()){
		if(b[i]==b[i-1]||b[i]==(b[i-1]+1)%m){
			//cout << i << ":connected" << endl;
			tmp += b[i];
		}else{
			//cout << i << "no" << endl;
			if(sum<tmp)
				sum = tmp;
			tmp = b[i];
		}
	}
	ll ans = 0;
	rep(i,n)ans+=a[i];
	cout << ans-sum << endl;
}