#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int N,L,R,X,Y,ans;

vector<pair<int,int>> line;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> X >> Y;
        line.push_back({X,Y});
    }
    sort(line.begin(), line.end());
    L = line[0].first;
    R = line[0].second;
    for(int i=1;i<N;i++) {
        X = line[i].first;
        Y = line[i].second;

        if (X>R) {
            //cout << "outside. L : " << L << ", R : " << R << "\n";
            ans+=R-L;
            L = X;
            R = Y;
        }
        else if (Y>R) {
            R = Y;
        }
    }
    ans+=R-L;
    cout << ans;
}