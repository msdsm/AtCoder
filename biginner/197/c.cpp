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


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll min = powl(2,30);
	int n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);

    // {0, 1, ..., n-1} の部分集合の全探索
	for (ll bit = 0; bit < (1<<n-1); ++bit) {
		vector<int> s;
		for (int i = 0; i < n-1; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
            	s.push_back(i);
            }
        }
/*
        cout << "debug start" << endl;
        cout << bit << ": {";
        for (int i = 0; i < (int)s.size(); ++i) {
        	cout << s[i] << " ";
        }
        cout << "}" << endl;
        cout << "debug end" << endl;
*/
        
        if(bit==0){
        	ll tmp = a[0];
        	rep2(1,i,n)tmp = tmp|a[i];
        	if(min>tmp)
        		min=tmp;
        }else{
        	ll tmp;
        	rep(i,s[0]+1){
        		if(i==0){
        			tmp = a[0];
        			continue;
        		}
        		tmp = tmp|a[i];
        	}
        	ll num = tmp;
        	rep(i,s.size()-1){
        		rep2(s[i]+1,j,s[i+1]+1){
        			if(j==s[i]+1){
        				tmp = a[j];
        				continue;
        			}
        			tmp = tmp|a[j];
        		}
        		num = num^tmp;
        	}
        	rep2(s[s.size()-1]+1,j,n){
        		if(j==s[s.size()-1]+1){
        			tmp = a[j];
        			continue;
        		}
        		tmp = tmp|a[j];
        	}
        	num = num^tmp;
        	if(min>num)
        		min=num;
        }
    }
    cout << min << endl;
}