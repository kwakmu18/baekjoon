#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, max;
    cin >> N;
    vector<int> arr(N), NGE(N);
    NGE[N-1]=-1;
    for(int i=0;i<N;i++) cin >> arr[i];
    stack<int> st;
    for(int i=N-1;i>=0;i--) {
        if (st.empty()) {
            NGE[i]=-1;
            st.push(arr[i]);
        }
        else {
            while (!st.empty() && st.top()<=arr[i]) st.pop();
            if (st.empty()) {
                NGE[i]=-1;
                st.push(arr[i]);
            }
            else {
                NGE[i]=st.top();
                st.push(arr[i]);
            }
        }
    }
    for(int i=0;i<N;i++) cout << NGE[i] << " ";
}