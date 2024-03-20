#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(void) {
    fastio();
    int N;
    cin >> N;
    vector<long long> solution(N);

    for(int i=0;i<N;i++) cin >> solution[i];
    sort(solution.begin(), solution.end());

    long long best_ph = INT_MIN;
    int best_one = 0, best_two = 0;

    for(int i=0;i<N;i++) {
        int left = i+1, right = N-1;
        while (left<=right) {
            int mid = (left+right)/2;

            if (abs(solution[i]+solution[mid])<=abs(best_ph)) {
                best_ph = solution[i]+solution[mid];
                best_one = solution[i]; best_two = solution[mid];
            }
            if (abs(solution[i]+solution[mid])>abs(solution[i]+solution[mid+1])) {
                left=mid+1;
            }
            else {
                right = mid-1;
            }
        }
    }

    cout << best_one << " " << best_two;
}