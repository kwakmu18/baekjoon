#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    unsigned int usedFruits = 0, now;
    int ans = 0;
    int N;
    
    cin >> N;
    vector<unsigned int> fruits(N);
    vector<int> fruitsCnt(10,0);
    
    for(int i=0;i<N;i++) cin >> fruits[i];

    int left = 0, right = 0;
    usedFruits |= (1<<fruits[0]);
    fruitsCnt[fruits[0]]++;

    while (left<N && right<N) {
        now = __builtin_popcount(usedFruits);
        //printf("left: %d, right: %d, usedFruits: %d, ans: %d, now: %d\n", left, right, usedFruits, ans, now);
        if (now<=2) {
            if (ans <= (right-left+1)) {
                ans = right-left+1;
            }
            right++;
            if (right<N) {
                fruitsCnt[fruits[right]]++;
                if (fruitsCnt[fruits[right]]==1) usedFruits |= (1<<fruits[right]);
            }
        }
        else {
            if (left==right) {
                right++;
                if (right<N) {
                    fruitsCnt[fruits[right]]++;
                    if (fruitsCnt[fruits[right]]==1) usedFruits |= (1<<fruits[right]);
                }
            }
            else {
                if (left<N && fruitsCnt[fruits[left]]>0) {
                    fruitsCnt[fruits[left]]--;
                    if (fruitsCnt[fruits[left]]==0) usedFruits ^= (1<<fruits[left]);
                }
                left++;
            }
        }
    }
    cout << ans << endl;
}