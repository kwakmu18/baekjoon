#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
int MaxValue(int arr[], int size, int base) {
	int ret=0;
	for(int i=0;i<size;i++) {
		if (arr[i]>ret) ret=arr[i];
	}
	if (base>ret) return base;
	else return ret;
}
int CntValue(int arr[], int size, int value) {
	int ret=0;
	for(int i=0;i<size;i++) {
		if (arr[i]==value) ret++;
	}
	return ret;
}
using namespace std;
void test() {
	int i;
	cin >> i;
}
int main(void) {
	int t;
	cin >> t;
	int *arr=new int[t];
	int *p=new int[4001]{0};
	int *m=new int[4001]{0};
	double sum=0;
	for(int i=0;i<t;i++) {
		scanf("%d", &arr[i]);
		sum+=arr[i];
		if (arr[i]>=0) p[arr[i]]++;
		else m[arr[i]*-1]++;
		
	}
	sort(arr, arr+t);
	int base=MaxValue(p, 4001, 0);
	int max=MaxValue(m, 4001, base);
	int maxcnt=CntValue(m,4001, max);
	int maxvalue;
	//for(int i=4000;i>=1;i--) printf("%d ", m[i]);
	maxcnt+=CntValue(p, 4001, max);
	if (maxcnt==1) {
		for(int i=4000;i>=1;i--) {
			if (m[i]==max) {
			maxvalue=-1*i;
			break;
		}
		}
		for(int i=0;i<=4000;i++) {
			if (p[i]==max) {
			maxvalue=i;
			break;
		}
		}
	}
	else {
		bool isnum=false;
		bool checkstatus=true;
		for(int i=4000;i>=1;i--) {
			if (m[i]==max) {
				if (isnum==true) {
				maxvalue=-1*i;
				checkstatus=false;
				break;
			}
			else {

			isnum=true;
		}
	}
}
if (checkstatus==true) {
		for(int i=0;i<=4000;i++) {
			if (p[i]==max) {
				if (isnum==true) {

					maxvalue=i;
					checkstatus=false;
					break;
				}
				else {
				isnum=true;
			}
		}
		}
}
}
	double avg=round(sum/t);
	if (avg==-0) avg=0;
	printf("%.0lf\n%d\n%d\n%d", avg, arr[(t-1)/2], maxvalue, arr[t-1]-arr[0]);
	delete []arr;
	delete []p;
	delete []m;
	//test();
	return 0;
}

