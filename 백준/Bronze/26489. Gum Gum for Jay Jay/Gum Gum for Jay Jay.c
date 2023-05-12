#include <stdio.h>

int main(void) {
    int cnt=0;
    char s[100];
    while (gets(s)!=NULL) cnt++;
    printf("%d", cnt);
}