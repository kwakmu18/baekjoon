#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int mv[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M,K;
    cin >> N >> M >> K;
    vector<vector<char> > gym(N);
    vector<vector<int> > cost(N);
    for(int i=0;i<N;i++) {
        gym[i].resize(M);
        cost[i].resize(M);
        string line;
        cin >> line;
        for(int j=0;j<M;j++) {
            gym[i][j] = line[j];
            cost[i][j] = 2147483647;
        }
    }

    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;

    queue<tuple<int, int, int> > q;
    q.push({y1-1, x1-1, 0});
    cost[y1-1][x1-1] = 0;

    while (!q.empty()) {
        auto [nowY, nowX, nowCost] = q.front();
        //cout << "nowY: " << nowY << " nowX: " << nowX << " nowCost: " << nowCost << "\n";
        q.pop();
        if (cost[nowY][nowX] < nowCost) continue;
        for(int i=0;i<4;i++) {
            for(int j=1;j<=K;j++) {
                int newY = nowY + mv[i][0] * j, newX = nowX + mv[i][1] * j, newCost = nowCost + 1;
                if (newY < 0 || newY >= N || newX < 0 || newX >= M || gym[newY][newX] == '#') break;
                if (cost[newY][newX] <= nowCost) break;
                if (cost[newY][newX] > newCost) {
                    cost[newY][newX] = newCost;
                    q.push({newY, newX, newCost});
                }
            }
        }
    }

    cout << (cost[y2-1][x2-1]==2147483647 ? -1:cost[y2-1][x2-1]);
}