#include <stdio.h>

void judge(int x){
  while(x > 0){
    if(x%10 == 7){
      printf("Yes\n");
      break;
    }
    x /= 10;
    if(x == 0){
      printf("No\n");
    }
  }
  return ;
}
int main(void){
  int num;
  scanf("%d",&num);
  judge(num);
  return 0;
}
