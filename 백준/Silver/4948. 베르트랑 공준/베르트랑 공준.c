#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 246913

int n,i,j;

int main(void) {

	int *prime = (int *)calloc(MAX_VALUE, sizeof(int));
	prime[1]=1;
	for(i=2;i<MAX_VALUE;i++) {
		if (!prime[i]) {
			for(j=i*2;j<MAX_VALUE;j+=i) prime[j]=1;
		}
	}

	while (1) {
		int cnt = 0;
		scanf("%d", &n);
		if (n==0) break;
		for(i=n+1;i<=2*n;i++) {
			if (!prime[i]) cnt++;
		}
		printf("%d\n", cnt);
	}
}