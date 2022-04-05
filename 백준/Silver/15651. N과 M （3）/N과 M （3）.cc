#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, j;
    cin >> n >> m;
    int *arr=new int[m+1];
    for(int i=0;i<m;i++) arr[i]=1;
    arr[m]=0;
    for(int i=0;i<(int)pow(n,m);i++) {
        arr[m]++;
        j=m;
        while (arr[j]>n) {
                    arr[j]=1;
                    arr[j-1]+=1;
                    j--;
        }
        
        for(int k=1;k<=m;k++) cout << arr[k] << " ";
        cout << "\n";
        }

} 