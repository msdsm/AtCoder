#include <stdio.h>
int main(void){
  int N,M,sum=0;
  scanf("%d",&N);
  scanf("%d",&M);
  int A[N];
  for(int i=0;i<N;i++){
    scanf("%d",&A[i]);
    sum += A[i];
  }
  int count=0;
  for(int i=0;i<N;i++){
    if(A[i] >= (double)sum/(4*M)){
      count++;
    }
  }
  if(count >= M){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}
