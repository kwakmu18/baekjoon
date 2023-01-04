#include <stdio.h>
#include <math.h>
main() {
	int m,n,i,j, cnt, sum=0, min, rcnt=0;
	scanf("%d", &m);
	scanf("%d", &n);
	min=n;
	for(i=m;i<=n;i++) {
		if (i==1) continue;
		cnt=0;
		for(j=1;j<=(int)sqrt(i);j++) if (i%j==0) cnt++;
		if (cnt==1) {
			sum+=i;
			rcnt++;
			if (min>i) min=i;
		}
	}
	if (rcnt==0) printf("-1");
	else printf("%d\n%d", sum, min);
}