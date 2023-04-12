#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll a[11];

int main(){
	string s;
	cin >> s;
	rep(i,s.length())a[s[i]-'1'+1]++;
	if(s.length()==1){
		if(atoi(s.c_str())%8==0){
			cout << "Yes" << endl;
			exit(0);
		}
	}else if(s.length()==2){
		if(atoi(s.c_str())%8==0){
			cout << "Yes" << endl;
			exit(0);
		}
		int num = 10*atoi(s.substr(1,1).c_str())+atoi(s.substr(0,1).c_str());
		//cout << num << endl;
		if(num%8==0){
			cout << "Yes" << endl;
			exit(0);
		}
	}else{
		if(a[1]>=1){
			if(a[1]>=2&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[2]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[3]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[4]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[5]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[6]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[7]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[8]>=1&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[9]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
		}

		if(a[3]>=1){
			if(a[1]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[2]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[3]>=2&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[4]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[5]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[6]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[7]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[8]>=1&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[9]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
		}

		if(a[5]>=1){
			if(a[1]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[2]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[3]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[4]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[5]>=2&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[6]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[7]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[8]>=1&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[9]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
		}

		if(a[7]>=1){
			if(a[1]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[2]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[3]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[4]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[5]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[6]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[7]>=2&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[8]>=1&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[9]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
		}

		if(a[9]>=1){
			if(a[1]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[2]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[3]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[4]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[5]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[6]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[7]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[8]>=1&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[9]>=2&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
		}

		if(a[2]>=1){
			if(a[1]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[2]>=2&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[3]>=1&&a[2]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[4]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[5]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[6]>=1&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[7]>=1&&a[2]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[8]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[9]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
		}

		if(a[4]>=1){
			if(a[1]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[2]>=1&&a[4]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[3]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[4]>=2&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[5]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[6]>=1&&a[4]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[7]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[8]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[9]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
		}

		if(a[6]>=1){
			if(a[1]>=1&&a[6]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[2]>=1&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[3]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[4]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[5]>=1&&a[6]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[6]>=2&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[7]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[8]>=1&&a[8]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[9]>=1&&a[6]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
		}

		if(a[8]>=1){
			if(a[1]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[2]>=1&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[3]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[4]>=1&&a[8]>=2){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[5]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[6]>=1&&a[4]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[7]>=1&&a[2]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[8]>=3){
				cout << "Yes" << endl;
				exit(0);
			}
			if(a[9]>=1&&a[6]>=1){
				cout << "Yes" << endl;
				exit(0);
			}
		}
	}
	cout << "No" << endl;
}