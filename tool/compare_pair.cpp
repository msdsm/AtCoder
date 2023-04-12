/*
pairの独自の比較関数を用いた
sort方法まとめ
*/

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

#define N 5

using namespace std;

void show(vector<pll> p,ll n){
	cout << endl;
	rep(i,n){
		cout << p[i].first << ' ' << p[i].second << endl;
	}
}


/*secondについて昇順(second優先)*/
bool compare_by_second(pair<long long int,long long int> a,pair<long long int,long long int> b){
	if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}/*この場合はこの自作関数を使わなくても
firstとsecondを入れ替えて普通に
std::sort(p.begin(),p.end())でいける*/


/*firstは昇順、secondは降順*/


/*firstは降順、secondは昇順*/


int main(){
	vector<pll> p(N);
	rep(i,N)cin>>p[i].first>>p[i].second;
	sort(p.begin(),p.end(),compare_by_second);
	show(p,N);
}