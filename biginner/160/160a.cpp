#include <iostream>

using namespace std;

int main(){
	char S[6];
	cin >> S;
	if(S[2] == S[3] && S[4] == S[5])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}