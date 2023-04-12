#include <stdio.h>

void print(long x,long y){
  long z;
  if(x-y>=0){
    z = x-y;
  }else{
    z = -1;
  }
  printf("%ld",z);
  return ;
}

int main(void){
  long num,m;
  scanf("%ld",&num);
  scanf("%ld",&m);
  long a[m];
  long sum=0;
  for(int i=0;i<m;i++){
    scanf("%ld",&a[i]);
    sum+=a[i];
    }
  print(num,sum);
  return 0;
}
