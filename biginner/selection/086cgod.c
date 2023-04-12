#include<stdio.h>
#include<stdlib.h>
 
int hoge(int tPoint, int xPoint, int yPoint, int t, int x, int y){
  int dif;
  dif = abs(x-xPoint) + abs(y - yPoint);
  if( (t - tPoint -dif) < 0 || (t - tPoint -dif) % 2 == 1) return 1;
  return 0;
}
 
int main(){
  int n, t, x, y;
  int tPoint=0, xPoint=0, yPoint=0;
  int isCorrect=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d %d %d",&t,&x,&y);
    isCorrect = hoge(tPoint,xPoint,yPoint,t,x,y);
    if(isCorrect == 1) {
      printf("No");
      return 0;
    }
  }
  printf("Yes");
}

このようにmain関数の途中でreturn 0をいれることでプログラムを途中で強制終了させられる
iが一回でも条件に引っ掛かったらnoを表示させてプログラムを終わらせて、
終わることなく最後まで行ったらyesを表示させている

ユーザー名:tickwa
