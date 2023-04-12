//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;


bool compare_by_second(pair<long long int,long long int> a,pair<long long int,long long int> b){
	if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

ll t;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<pll> p(n);
	rep(i,n)cin>>p[i].first>>p[i].second;
	sort(p.begin(),p.end(),compare_by_second);

/*
	cout << "debug start" << endl;
	rep(i,n)cout << p[i].first << ' ' << p[i].second << endl;
	cout << "debug end" << endl;
*/	
	
	rep(i,n){
		t+=p[i].first;
		if(t>p[i].second){
			cout << "No" << endl;
/*
			cout << "debug start" << endl;
			cout << t << endl;
			cout << i << endl;
			cout << "debug end" << endl;
*/			
			
			return 0;
		}
	}
	cout << "Yes" << endl;
}