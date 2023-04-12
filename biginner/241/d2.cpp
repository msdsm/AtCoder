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
	ll q;
	cin >> q;
	multiset<ll> st;
	rep(iii,q){
/*
		cout << "debug start" << endl;
		cout << iii << endl;
		cout << "debug end" << endl;
*/		
		
		int c;
		cin >> c;
		if(c==1){
			ll x;
			cin >> x;
			st.insert(x);
		}else if(c==2){
			ll x,k;
			cin >> x >> k;
			auto itr = upper_bound(st.begin(),st.end(),x);
			if((*st.begin())>x){
				cout << -1 << endl;
				continue;
			}
			itr--;
			ll tmp = 0;
			auto itr2 = itr;
			while(itr2!=st.begin()){
				itr2--;
				tmp++;
			}
			tmp++;
			if(tmp<k){
				cout << -1 << endl;
				continue;
			}
			rep(i,k-1){
				itr--;
			}
			cout << *(itr) << endl;
		}else{
			ll x,k;
			cin >> x >> k;
			auto itr = lower_bound(st.begin(),st.end(),x);
			auto itr2 = st.end();
			itr2--;
			if((*itr2)<x){
				cout << -1 << endl;
				continue;
			}
			itr2 = itr;
			ll tmp = 0;
			while(itr2!=st.end()){
				itr2++;
				tmp++;
			}
			if(tmp<k){
				cout << -1 << endl;
				continue;
			}
			rep(i,k-1){
				itr++;
			}
			cout << *(itr) << endl;
		}
	}
}