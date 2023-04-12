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

ll ans = 0;
ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	set<ll> st;
	map<ll, ll> mp;
	rep(i,n){
		st.insert(a[i]);
		mp[a[i]]++;
	}
	a.clear();
	for(auto itr=st.begin();itr!=st.end();itr++){
		cnt += (mp[*itr])-1;
		a.push_back(*itr);
	}
/*
	cout << "debug start cnt" << endl;
	cout << cnt << endl;
	cout << "debug end" << endl;


	cout << "debug start a" << endl;
	rep(i,n)cout<<a[i]<< ' ';
	cout<<endl;
	cout << "debug end" << endl;
*/	
	
	
	
	rep(i,n){
/*
		cout << "debug start" << endl;
		cout << i << endl;
		cout << mp[i+1] << endl;
		cout << ans << endl;
		cout << "debug end" << endl;
*/		
		
		if(mp[i+1]>0){
			ans = i+1;
			continue;
		}else{
			if(cnt>=2){
				cnt -= 2;
				ans = i+1;
				continue;
			}else if(cnt==1){
				cnt -= 1;
				if(a.size()==0)
					break;
				ll tmp = a[a.size()-1];
				if(tmp<=i+1){
					break;
				}else{
					ans = i+1;
					mp[tmp]=0;
					a.pop_back();
					continue;
				}
			}else{
				if(a.size()<2)
					break;
				ll tmp = a[a.size()-1];
				if(tmp<=i+1){
					break;
				}else{
					mp[tmp]=0;
					a.pop_back();
					if(a.size()<1)
						break;
					ll tmp2 = a[a.size()-1];
					if(tmp2<=i+1){
						break;
					}else{
						ans = i+1;
						mp[tmp2]=0;
						a.pop_back();
					}
				}
			}
		}
	}
	cout << ans << endl;
}