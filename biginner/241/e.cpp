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

ull ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	cinf(a,n);
	if(k==1){
		cout << a[0] << endl;
		return 0;
	}
	/*
	if(a[0]%n==0){
		cout << k*a[0] << endl;
		return 0;
	}
	*/
	vector<ll> list;
	list.push_back(0);
	ll key;
	set<ll> st;
	st.insert(0);
	ll x = a[0];
	rep(i,n+3){
		ll tmp = x%n;
		list.push_back(tmp);
		if(st.count(tmp)>0){
			key=tmp;
			break;
		}
		st.insert(tmp);
		x += a[tmp];
	}
	bool flag = false;
	ll it = 0;
	ll start = 0;
	vector<ll> t;//周期
	while(true){
		if(list[it]==key){
			if(flag){
				break;
			}else{
				flag=true;
				t.push_back(list[it]);
				start = it;
			}
		}else{
			if(flag)
				t.push_back(list[it]);
		}
		it++;
	}
/*
	cout << "debug start" << endl;
	rep(i,t.size()){
		cout << t[i] << endl;
	}
	cout << "debug end" << endl;
*/

	ll length = t.size();
	vector<ll> sum(length);
	sum[0]=a[t[0]];
	rep2(1,i,length){
		sum[i]=sum[i-1]+a[t[i]];
	}
	ll pre = 0;
	if(k<start){
		rep(i,k){
			ans += a[pre];
			pre=ans%n;
		}
		cout << ans << endl;
		return 0;
	}
	pre=0;
	rep(i,start){
		ans += a[pre];
		pre = ans%n;
	}
	ll num = k-start;
	ll num2 = num/length;
	ans += (num2*sum[length-1]);
	ll num3 = num%length;
	if(num3!=0){
		ans+=sum[num3-1];
	}
	cout << ans << endl;
}