#include <iostream>

using namespace std;

int answer[1001][10];

int main(void) {
    for(int i=0;i<=9;i++) answer[1][i] = 1;
    
    for(int j=2;j<=1000;j++) {
        answer[j][0] = (answer[j-1][7]) % 1234567;
        answer[j][1] = (answer[j-1][2] + answer[j-1][4]) % 1234567;
        answer[j][2] = (answer[j-1][1] + answer[j-1][3] + answer[j-1][5]) % 1234567;
        answer[j][3] = (answer[j-1][2] + answer[j-1][6]) % 1234567;
        answer[j][4] = (answer[j-1][1] + answer[j-1][5] + answer[j-1][7]) % 1234567;
        answer[j][5] = (answer[j-1][2] + answer[j-1][4] + answer[j-1][6] + answer[j-1][8]) % 1234567;
        answer[j][6] = (answer[j-1][3] + answer[j-1][5] + answer[j-1][9]) % 1234567;
        answer[j][7] = (answer[j-1][0] + answer[j-1][4] + answer[j-1][8]) % 1234567;
        answer[j][8] = (answer[j-1][5] + answer[j-1][7] + answer[j-1][9]) % 1234567;
        answer[j][9] = (answer[j-1][6] + answer[j-1][8]) % 1234567;
    }

    int T, N;

    scanf("%d", &T);

    for(int i=0;i<T;i++) {
        scanf("%d", &N);
        int answerSum = 0;
        for(int i=0;i<=9;i++) answerSum += answer[N][i];

        printf("%d\n", answerSum%1234567);
    }
}