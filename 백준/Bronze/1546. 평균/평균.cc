#include <stdio.h>
main() {
	double a[1000];
	int i,n,M=0;
	double sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%lf",&a[i]);
		if (M<a[i]) M=a[i];
	}
	for(i=0;i<n;i++) {
		a[i]=a[i]/M*100.0;
		sum+=a[i];
	}
	printf("%lf",sum/n);
}