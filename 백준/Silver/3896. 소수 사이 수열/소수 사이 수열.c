#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 1299710

int T, k, prime[MAX_VALUE];

int main(void) {
	prime[1] = 1;
	for(int i=2;i<MAX_VALUE;i++) {
		if (!prime[i]) {
			for(int j=i*2;j<MAX_VALUE;j+=i) prime[j] = 1;
		}
	}
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &k);
		if (!prime[k]) {
			printf("0\n");
			continue;
		}
		int left = k, right = k;
		while (prime	[left]) left--;
		while (prime[right]) right++;
		printf("%d\n", right-left);
	}
}