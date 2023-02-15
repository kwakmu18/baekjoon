#include <stdio.h>
#include <math.h>

int findMinUniqNum(int);
int main(){
    int num;
    while(scanf("%d", &num)!=EOF){
        int res = findMinUniqNum(num);
        printf("%d\n", res);
    }
    return 0;
}

int findMinUniqNum(int num){
    if (num >= 987654321){ return 0; }
    if (num == 0) {return 1;}
    int i, n;
    int res = 0;

    int check[10] = {0,};
    check[0] = 1;
    int nSize = floor(log10(num) + 1);

    for (i = 0; i<nSize; i++){
        n = num / (int)pow(10, nSize-1-i);
        if (check[n] == 0 && i != nSize-1){
            // 중복을 발견하지 못했으면 값 저장
            res += n * pow(10, nSize-1-i);
            check[n] = 1;
        }
        else{
            // 중복을 발견하거나 끝에 다다른 경우
            break; 
        }
        num = num % (int)pow(10, nSize-1-i);
    } 
    // i = 최초로 중복된 값의 인덱스 or 중복 없어서 끝까지 간 경우
    // n = 최초로 중복된 값

    // 중복 값보다 큰 값이면서 사용되지 않은 숫자 집어넣기
    while(n < 9){
        if (check[n+1] == 0){
            res += (n+1) * pow(10, nSize-1-i);
            check[n+1] = 1;
            i++;
            break;
        }
        n++;
    }
    // 중복된 값이 9면 자리올림하여 다시 계산
    if ( n == 9 ){
        return findMinUniqNum(res+ pow(10, nSize-i));
    }
    
    // 중복된 값 이래로 다시 업데이트
    int count = 0;
    while(i<nSize){
        if (check[count] == 0){
            res += count * pow(10, nSize-1-i);
            check[count] = 1;
            i++;
        }
        count++;
    }
    return res;
}