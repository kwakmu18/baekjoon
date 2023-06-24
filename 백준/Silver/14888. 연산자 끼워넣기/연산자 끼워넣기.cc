#include <bits/stdc++.h>

using namespace std;

char op[4] = {'+', '-', '*', '/'};

int N, maxResult = -1000000001, minResult = 1000000001;
vector<int> numbers;
map<char,int> operators;
map<char,int> visited;
vector<char> nowOperators;

void dfs(int cnt) {
    if (cnt==N-1) {
        int operand1 = numbers[0], operand2;
        for(int i=0;i<cnt;i++) {
            operand2=numbers[i+1];
            switch (nowOperators[i]) {
                case '+':
                    operand1+=operand2;
                    break;
                case '-':
                    operand1-=operand2;
                    break;
                case '*':
                    operand1*=operand2;
                    break;
                case '/':
                    operand1/=operand2;
                    break;
            }
            
        }
        if (operand1>maxResult) maxResult=operand1;
        if (operand1<minResult) minResult=operand1;
        return;
    }

    for(auto i = operators.begin();i!=operators.end();i++) {
        char nowOp = (*i).first;
        int nowCnt = (*i).second;

        if (visited[nowOp]>=nowCnt) continue;
        visited[nowOp]++;
        nowOperators.push_back(nowOp);
        dfs(cnt+1);
        nowOperators.pop_back();
        visited[nowOp]--;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    numbers.resize(N);
    for(int i=0;i<N;i++) cin >> numbers[i];

    int cnt;
    for(int i=0;i<4;i++) {
        cin >> cnt;
        operators[op[i]]=cnt;
        visited[op[i]]=0;
    }

    dfs(0);

    cout << maxResult << "\n" << minResult;

    return 0;
}