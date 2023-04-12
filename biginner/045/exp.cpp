#include <iostream>
#include <cstring>

using namespace std;

long long j;

int main(void){
	string s = "qwertyuiop";
	for(long long i=0;i<s.length();i++){
		if(i%2==0&&i>0)
			j++;
		cout << s.substr(j,i+1) << endl;
	}
}