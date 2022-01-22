//2729 Silver 5
#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string s1, s2;
    int t;
    cin >> t;
    while (t--) {
        cin >> s1 >> s2;
        int len1=s1.length(), len2=s2.length();
        if (len2>=len1) {
            s1.swap(s2);
            int tmp=len2;
            len2=len1;
            len1=tmp;
        }
            int *ans=new int[len1+1]{0};
            for(int i=len1;i>=1;i--) ans[i]=s1[i-1]-48;
            for(int i=len1;i>len1-len2;i--) ans[i]+=(s2[i-len1+len2-1]-48);
            for(int i=len1;i>=1;i--) {
                if (ans[i]>=2) {
                    ans[i-1]++;
                    ans[i]-=2;
                }
            }
            int onestart=0;
            bool iszero=true;
            for(int i=0;i<=len1;i++) {
                if (ans[i]!=0) {
                    onestart=i;
                    iszero=false;
                    break;
                }
            }
            if (iszero) {
                cout << 0;
                continue;
            }
            for(int i=onestart;i<=len1;i++) {
                if (i==0) if (ans[i]==0) continue;
                cout << ans[i];
            }
            cout << endl;
    }
}