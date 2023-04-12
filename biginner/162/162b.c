#include <stdio.h>
int main(void){
  int N;
  scanf("%d",&N);
  int a[N];
  long int sum=0;
  for(int i=0;i<N;i++){
    if((i+1)%3==0||(i+1)%5==0){
      a[i]=0;
    }else{
      a[i]=i+1;
    }
    sum+=a[i];
  }
  printf("%ld",sum);
  return 0;
}
