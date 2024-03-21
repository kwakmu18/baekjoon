#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

map<char, int> digits;
int main(void) {
    fastio();
    
    int N;
    cin >> N;

    string line;
    for(int i=0;i<N;i++) {
        cin >> line;
        int len = line.length();
        for(int j=0;j<len;j++) {
            if (digits.find(line[j])==digits.end()) digits[line[j]] = pow(10, len-1-j);
            else digits[line[j]] += pow(10, len-1-j);
        }
    }
    
    vector<int> nums;
    for(auto i=digits.begin(); i!=digits.end(); i++) {
        nums.push_back((*i).second);
    }
    sort(nums.begin(), nums.end(), greater<int>());

    int now = 9, tot = 0;
    for(auto i=nums.begin(); i!=nums.end(); i++) {
        tot += (now--) * (*i);
    }
    cout << tot;
}