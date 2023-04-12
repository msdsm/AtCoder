#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare_int(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(void){
	long double a,b;
	long long n;
	scanf("%Lf",&a);scanf("%Lf",&b);scanf("%lld",&n);
	long int f[n+1];
	for(int i=0;i<=n;i++){
		f[i] = (long int)floorl(a*i/b)-(long int)a*(long int)floorl(i/b);
	}

	qsort(f, n+1, sizeof(long int), compare_int);
	printf("%ld\n",f[n]);
	return 0;
}