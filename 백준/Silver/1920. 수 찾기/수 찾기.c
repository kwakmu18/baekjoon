#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	if (*(int *)a>*(int *)b) return 1;
	else if (*(int *)a<*(int *)b) return -1;
	else return 0;
}

int main(void) {
	int N, M;
	scanf("%d", &N);
	int *array = (int *)malloc(sizeof(int)*N);
	int i, j;
	for(i=0;i<N;i++) scanf("%d", &array[i]);
	qsort(array, N, sizeof(int), compare);

	//for(i=0;i<N;i++) {
	//	for(j=0;j<N-1;j++) {
	//		if (array[j]>array[j+1]) {
	//			int temp = array[j];
	//			array[j] = array[j+1];
	//			array[j+1] = temp;
	//		}
	//	}
	//}

	int find;
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &find);
		int flag = 0;
		int left = 0, right = N-1, mid;
		while (left<=right) {
			mid = (left+right)/2;
			if (array[mid]>find) right=mid-1;
			else if (array[mid]==find) {
				flag = 1;
				break;
			}
			else left = mid+1; 
		}
		printf("%d\n", flag ? 1 : 0);
	}
}