//これはメモであってコンパイル不可


/*
バグらない二分探索の書き方
判定関数f(x): T → bool (s<=x<tの半開区間)
が広義単調増加であるときに
f(x)=trueとなる最小のxをO(log(t-s))で求めるアルゴリズム
*/


#include <iostream>

using namespace std;


int main(){

	int ng = s-1, ok = t;//区間範囲外に設定する
	//f(ng)=false, f(ok)=trueとしたい。

	/*
	判定関数の作成の際に
	関数範囲外の変数を参照したい場合は
	ラムダ式を用いる。
	*/
	auto f = [&](T x){//Tからboolへの写像が広義単調増加
		if(/*計算式*/)
			return true;
		else
			return false;
	};



	while(ok - ng > 1){
		int mid = (ng + ok) / 2;
		(f(mid) ? ok : ng) = mid;
	}

	if(ok == t)
		cout << "for all x, f(x) = false" << endl;
		//すべてfalse、つまり探索失敗を検知
	else
		cout << ok << endl;
}