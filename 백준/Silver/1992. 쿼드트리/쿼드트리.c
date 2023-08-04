#include <stdio.h>
#include <string.h>

int N, id;
char image[64][64];
char result[20000];

void quadTree(int y, int x, int size) {
	int base = image[y][x];
	int flag = 1;
	for(int i=y;i<y+size;i++) {
		for(int j=x;j<x+size;j++) {
			if (image[i][j]!=base) {
				flag = 0;
				break;
			}
		}
		if (!flag) break;
	}
	if (flag) {
		result[id++]=base;
		return;
	}
	else {
		result[id++]='(';
		size /= 2;
		quadTree(y,x,size);
		quadTree(y,x+size,size);
		quadTree(y+size,x,size);
		quadTree(y+size,x+size,size);
		result[id++]=')';
		return;
	}
}

int main(void) {
	scanf("%d", &N);

	for(int i=0;i<N;i++) {
		scanf("%s", image[i]);
	}
	quadTree(0,0,N);
	result[id]='\0';
	printf("%s", result);
}