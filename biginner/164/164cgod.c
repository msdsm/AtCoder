#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int compare(const void* a, const void* b) {
	return (strcmp((char*)a, (char*)b));
}
 
int main(){
	int N, ans = 1;
	char S[200000][11];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", S[i]);
	qsort((void*)S, N, sizeof(S[0]), compare);
	for (int i = 0; i < N - 1; i++) if(strcmp(S[i], S[i + 1]) != 0) ans++;
	printf("%d", ans);
	return 0;
}

/*  ユーザー名:ttyuknt023 */
