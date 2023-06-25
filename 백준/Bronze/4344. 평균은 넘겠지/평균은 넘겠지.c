#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        scanf("%d", &N);
        double totalScore = 0;
        int *score = (int *)malloc(sizeof(int)*N);
        for(int i=0;i<N;i++) {
            scanf("%d", &score[i]);
            totalScore+=(double)score[i];
        }
        double avg = totalScore / N;
        int cnt = 0;
        for(int i=0;i<N;i++) {
            if ((double)score[i]>avg) cnt++;
        }
        int ratio = 100*cnt/N;
        double r = 100.0*cnt/N-ratio; 
        r*=10; int first = (int)r%10;
        r*=10; int second = (int)r%10;
        r*=10; int third = (int)r%10;
        r*=10; int fourth = (int)r%10;
        if (fourth>=5) third++;
        if (third==10) {
            third=0;
            second++;
        }
        if (second==10) {
            second=0;
            first++;
        }
        if (first==10) {
            first=0;
            ratio++;
        }
        printf("%d.%d%d%d%%\n", ratio,first,second,third);
    }
}