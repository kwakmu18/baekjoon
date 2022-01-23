//1914 Silver 2
#include <iostream>
#include <cmath>
using namespace std;
int cnt=0;

void Hanoi(int num, char from, char by, char to) {
	if (num==1) {
	//printf("%c %c\n", from, to);
	cout << from << " " << to << "\n";
}
	else {
		Hanoi(num-1, from, to, by);
		//printf("%c %c\n", from, to);
		cout << from << " " << to << "\n";
		Hanoi(num-1, by, from, to);
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
    int *ans=new int[32]{0};
    ans[31]=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=31;j++) ans[j]*=2;
        for(int j=31;j>=1;j--) {
            if (j>=10) {
                ans[j-1]+=ans[j]/10;
                ans[j]%=10;
            }
        }
    }
    int index=0;
    for(int i=0;i<=31;i++) {
        if (ans[i]!=0) {
            index=i;
            break;
        }
    }
    ans[31]-=1;
    for(int i=index;i<=31;i++) cout << ans[i];
    cout << "\n";
	if (n>20) return 0;
	Hanoi(n, '1', '2', '3');
	return 0;
}