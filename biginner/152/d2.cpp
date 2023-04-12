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

pair<ll,ll> z = make_pair(-1,-1);

ll ans;

pair<ll,ll> f(ll x){
	string s = to_string(x);
	ll a = stoi(s.substr(0,1));
	ll b = stoi(s.substr(s.length()-1,1));
	if(b==0)
		return z;
	//return make_pair(a,b);
	return pair<ll,ll>(a,b);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	cin >> n;
	multiset<pair<ll,ll>> ms1;
	multiset<pair<ll,ll>> ms2;
	multiset<pair<ll,ll>> ms3;
	set<pair<ll,ll>> st1;
	set<pair<ll,ll>> st2;
	set<pair<ll,ll>> st3;
	arep(1,i,n+1){
		if(f(i)==z)
			continue;
		else if(f(i).first>f(i).second){
			ms1.insert(f(i));
			st1.insert(f(i));
		}
		else if(f(i).first<f(i).second){
			ms2.insert(f(i));
			st2.insert(f(i));
		}
		else{
			ms3.insert(f(i));
			st3.insert(f(i));
		}
	}

/*
	for(auto itr=ms1.begin();itr!=ms1.end();itr++){
		cout << itr->first << endl;
		cout << itr->second << endl;
		cout << ms1.count(*itr) << endl;
	}
*/
	for(auto itr=st1.begin();itr!=st1.end();itr++){
		pair<ll,ll> p;
		p.first=itr->second;
		p.second=itr->first;
/*
		cout << "debug start" << endl;
		cout << itr->first << ' ' << itr->second << endl;
		cout << "debug end" << endl;


		cout << "debug start" << endl;
		cout << ms1.count(*itr) << endl;
		cout << ms2.count(p) << endl;
		cout << "debug end" << endl;
*/
		
		
		
		ans += 2*ms1.count(*itr)*ms2.count(p);
	}

	for(auto itr=st3.begin();itr!=st3.end();itr++){
		ans += (ms3.count(*itr)*ms3.count(*itr));
/*
		cout << "debug start" << endl;
		cout << itr->first << ' ' << itr->second << endl;
		cout << "debug end" << endl;


		cout << "debug start" << endl;
		cout << ms3.count(*itr) << endl;
		cout << "debug end" << endl;
*/		
		
		
		
	}
	cout << ans << endl;
}