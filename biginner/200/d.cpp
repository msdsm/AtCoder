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
	int n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	rep(i,n)a[i]=a[i]%200;
	if(n>7){
		cout << "Yes" << endl;
		ll data[200];
		rep(i,200)data[i]=0;
		srand(time(NULL));
		rep(k,(1<<20)){
			ll bit = rand()%(1<<20)+1;
			ll tmp = 0;
			for(ll i = 0;i<20;i++){
				if(bit&(1<<i)){
					tmp+=a[i];
				}
			}
			tmp=tmp%200;
			data[tmp++];
		}
		rep(i,200){
        	if(data[i]>=2){	
        		ll r = i;
        		bool flag = false;	
        		srand(time(NULL));
        		rep(k,(1<<20)){
        			ll bit = rand()%(1<<20)+1;
        			ll tmp = 0;
        			vector<ll> b;
        			for(int j = 0; j < 20; ++j){
            			if(bit & (1<<j)){ // 列挙に j が含まれるか
            				tmp += a[j];
            				b.push_back(j+1);
            			}            
            		}
            		tmp%=200;
            		if(tmp==r){            			
            			if(flag){
            				cout << b.size() << ' ';
            				rep(i,b.size()){
            					if(i==b.size()-1)
            						cout << b[i] << endl;
            					else
            						cout << b[i] << ' ';
            				}
            				return 0;
            			}else{
            				flag = true;
            				cout << b.size() << ' ';
            				rep(i,b.size()){
            					if(i==b.size()-1)
            						cout << b[i] << endl;
            					else
            						cout << b[i] << ' ';
            				}
            			}
            		}
            	}
            }
        }
	}else{
		//bit探索
		ll data[200];
		rep(i,200)data[i]=0;
		for(ll bit = 1; bit < (1<<n); ++bit){
			ll tmp = 0;
			for(int i = 0; i < n; ++i){
            	if(bit & (1<<i)){ // 列挙に i が含まれるか
            		tmp += a[i];
            	}            
            }      
/*
        cout << "debug start" << endl;
        cout << bitset<16>(bit) << endl;
        cout << tmp%200 << endl;
        cout << "debug end" << endl;
*/        
            data[tmp%200]++;
        }
        rep(i,200){
        	if(data[i]>=2){
/*
    		cout << "debug start" << endl;
    		cout << i << endl;
    		cout << "debug end" << endl;
*/    		
        		cout << "Yes" << endl;   
        		ll r = i;
        		bool flag = false;	
        		for(ll bit = 1; bit < (1<<n); ++bit){
        			ll tmp = 0;
        			vector<ll> b;
        			for(int j = 0; j < n; ++j){
            			if(bit & (1<<j)){ // 列挙に j が含まれるか
            				tmp += a[j];
            				b.push_back(j+1);
            			}            
            		}
            		tmp%=200;
            		if(tmp==r){
/*
            			cout << "debug start" << endl;
            			cout << tmp << endl;
            			cout << "debug end" << endl;
*/            			
            			
            			if(flag){
            				cout << b.size() << ' ';
            				rep(i,b.size()){
            					if(i==b.size()-1)
            						cout << b[i] << endl;
            					else
            						cout << b[i] << ' ';
            				}
            				return 0;
            			}else{
            				flag = true;
            				cout << b.size() << ' ';
            				rep(i,b.size()){
            					if(i==b.size()-1)
            						cout << b[i] << endl;
            					else
            						cout << b[i] << ' ';
            				}
            			}
            		}
            	}
            }
            if(i==199){
            	cout << "No" << endl;
            	return 0;
            }
        }
    }
}