#include <iostream>

using namespace std;

int main(){
	int a,b,c,d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	while(!(c<=0 || a<=0)){
		c=c-b;
		if(c <= 0){
			cout << "Yes" << endl;
			goto Exit;
		}
		a=a-d;
		if(a <= 0){
			cout << "No" << endl;
			goto Exit;
		}
	}
	Exit : 
	;
}