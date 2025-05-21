#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int total;
    int sizes[6];
    int T, P;
    int tResult = 0;

    cin >> total;
    for(int i=0;i<6;i++) cin >> sizes[i];
    cin >> T >> P;

    for(int i=0;i<6;i++) tResult += sizes[i]%T==0 ? sizes[i]/T : (sizes[i]/T)+1;

    cout << tResult << "\n" << total/P << " " << total%P;

    
}