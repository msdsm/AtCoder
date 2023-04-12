#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

class STACK{
private:
	string s;
public:
	/*STACK(string ss){
		s = ss;
	}*/

	void push(char num){
		s+=num;
	}

	void pop(){
		if(!s.empty())
			s.pop_back();
	}

	bool isempty(){
		if(s.length()==0)
			return true;
		else
			return false;
	}

	int size(){
		return s.length();
	}

	void list(){
		cout << s << endl;
	}
};

int main(){
	STACK data;
	string s;
	cin >> s;
	rep(i,s.length()){
		if(s[i]=='0')
			data.push('0');
		else if(s[i]=='1')
			data.push('1');
		else if(s[i]=='B')
			data.pop();
		}
	data.list();
}