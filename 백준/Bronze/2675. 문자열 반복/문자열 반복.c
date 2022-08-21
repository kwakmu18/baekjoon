////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#include <string.h>
////#include <math.h>
////int main(void)
////{
////	int cnt = 0;
////	char col1[7];
////	char res1[2] = "_";
////	char res2[2] = "_";
////	char res3[10] = "_";
////	while (cnt < 3)
////	{
////		scanf("%s", col1);
////		if (strcmp(res1,"")==0 && strcmp(res2, "0") == 0) {
////			cnt = 3;
////			strcpy(res3, "");
////		} 
////		else {
////			if (strcmp(col1, "black") == 0)
////			{
////				cnt++;
////				if (cnt == 1) strcpy(res1, "");
////				else if (cnt == 2) strcpy(res2, "0");
////				else if (cnt == 3) strcpy(res3, "");
////			}
////			if (strcmp(col1, "brown") == 0)
////			{
////				cnt++;
////				if (cnt == 1) strcpy(res1, "1");
////				else if (cnt == 2) strcpy(res2, "1");
////				else if (cnt == 3) strcpy(res3, "0");
////			}
////			if (strcmp(col1, "red") == 0)
////			{
////				cnt++;
////				if (cnt == 1) strcpy(res1, "2");
////				else if (cnt == 2) strcpy(res2, "2");
////				else if (cnt == 3) strcpy(res3, "00");
////			}
////			if (strcmp(col1, "orange") == 0)
////			{
////				cnt++;
////				if (cnt == 1) strcpy(res1, "3");
////				else if (cnt == 2) strcpy(res2, "3");
////				else if (cnt == 3) strcpy(res3, "000");
////			}
////			if (strcmp(col1, "yellow") == 0)
////			{
////				cnt++;
////				if (cnt == 1) strcpy(res1, "4");
////				else if (cnt == 2) strcpy(res2, "4");
////				else if (cnt == 3) strcpy(res3, "0000");
////			}
////			if (strcmp(col1, "green") == 0)
////			{
////				cnt++;
////				if (cnt == 1) strcpy(res1, "5");
////				else if (cnt == 2) strcpy(res2, "5");
////				else if (cnt == 3) strcpy(res3, "00000");
////			}
////			if (strcmp(col1, "blue") == 0)
////			{
////				cnt++;
////				if (cnt == 1) strcpy(res1, "6");
////				else if (cnt == 2) strcpy(res2, "6");
////				else if (cnt == 3) strcpy(res3, "000000");
////			}
////			if (strcmp(col1, "violet") == 0)
////			{
////				cnt++;
////				if (cnt == 1) strcpy(res1, "7");
////				else if (cnt == 2) strcpy(res2, "7");
////				else if (cnt == 3) strcpy(res3, "0000000");
////			}
////			if (strcmp(col1, "grey") == 0)
////			{
////				cnt++;
////				if (cnt == 1) strcpy(res1, "8");
////				else if (cnt == 2) strcpy(res2, "8");
////				else if (cnt == 3) strcpy(res3, "00000000");
////			}
////			if (strcmp(col1, "white") == 0)
////			{
////				cnt++;
////				if (cnt == 1) strcpy(res1, "9");
////				else if (cnt == 2) strcpy(res2, "9");
////				else if (cnt == 3) strcpy(res3, "000000000");
////			}
////		}
////	}
////	printf("%s%s%s", res1, res2, res3);
////	return 0;
////}
////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#include <string.h>
////main() {
////	char s[100];
////	int a[26] = { 0 };
////	scanf("%s", s);
////	for (int i = 0; i < strlen(s); i++) {
////		for (char j = 'a'; j <= 'z'; j++) {
////			if (a[j - 97] == 0) {
////				if (s[i] == j) a[j - 97] = i + 1;
////			}
////			else continue;
////		}
////	}
////	for (int i = 0; i < 26; i++) {
////		if (a[i] == 0) a[i] = -1;
////		else a[i] -= 1;
////		printf("%d ", a[i]);
////	}
////}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//main() {
//	char s[1000000];
//	int cnt[52], count=0;
//	scanf("%s", s);
//	for (int i = 0; i < strlen(s); i++) {
//		for (char j = 'A'; j <= 'Z'; j++) if (s[i] == j) cnt[j - 65] += 1;
//		for (char j = 'a'; j <= 'z'; j++) if (s[i] == j) cnt[j - 71] += 1;
//		}
//	int max = 0;
//	for (int i = 0; i < 52; i++) if (max <= cnt[i]) max = i;
//	for (int i = 0; i < 26; i++) {
//		if (max == cnt[i] && cnt[i] == cnt[i + 26]) {
//			printf("%c", i + 65);
//			count += 1;
//		}
//		else if (max == cnt[i] && cnt[i] != cnt[i + 26]) {
//			printf("?");
//			count += 1;
//		}
//	}
//	if (count != 1) printf("%c", max + 65);
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
main() {
	int T, R;
	char word[20];
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %s", &R, word);
		for (int j = 0; j < strlen(word); j++) {
			for (int k = 0; k < R; k++) printf("%c", word[j]);
		}
		printf("\n");
	}
}