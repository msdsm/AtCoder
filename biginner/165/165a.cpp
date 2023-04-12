#include <iostream>

using namespace std;

int main(){
	int k,a,b;
	cin >> k >> a >> b;
	int flag = a%k;
	if(flag == 0)
		cout << "OK" << endl;
	else if(b >= a + k - a%k)
		cout << "OK" << endl;
	else 
		cout << "NG" << endl; 
}