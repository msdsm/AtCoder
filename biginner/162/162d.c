#include <stdio.h>
int main(void){
  long long count=0;
  int N;
  scanf("%d",&N);
  char S[N];
  scanf("%s",S);
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      for(int k=j+1;k<N;k++){
        if(j-i!=k-j && S[i]!=S[j] && S[j]!=S[k] && S[k]!=S[i]){
          count += 1;
        }
      }
    }
  }
  printf("%lld",count);
  return 0;
}
