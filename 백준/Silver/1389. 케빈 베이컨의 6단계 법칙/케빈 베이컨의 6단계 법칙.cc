#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N,M,A,B;
    cin >> N >> M;
    bool **check = new bool *[N];
    for(int i=0;i<N;i++) check[i] = new bool[N]{false};
    for(int i=0;i<M;i++) {
        cin >> A >> B;
        check[A-1][B-1]=true;
        check[B-1][A-1]=true;
    }
    vector<vector<int>> relation(N);
    vector<vector<int>> distance(N);
    for(int i=0;i<N;i++) {
        distance[i].resize(N);
        for(int j=0;j<N;j++) {
            distance[i][j]=10001;
            if (check[i][j]) relation[i].push_back(j);
        }
    }
    int *ans = new int[N]{0};
    int minDistIndex = 0;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<N;i++) {
        pq.push({0,i});
        while (!pq.empty()) {
            int nowPerson = pq.top().second, nowDist = -pq.top().first;
            pq.pop();
            if (nowDist>distance[i][nowPerson]) continue;
            int size = relation[nowPerson].size();
            for(int j=0;j<size;j++) {
                int newDist = nowDist+1, newPerson = relation[nowPerson][j];
                if (newDist<distance[i][newPerson]) {
                    distance[i][newPerson] = newDist;
                    pq.push({-newDist, newPerson});
                }
            }
        }
        for(int j=0;j<N;j++) {
            if (j!=i) ans[i]+=distance[i][j];
        }
        if (ans[i]<ans[minDistIndex] && minDistIndex<i) minDistIndex=i;
    }
    cout << minDistIndex+1;
}