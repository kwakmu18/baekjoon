#include<bits/stdc++.h>
#define MAX 101 //100 -> doublefree 컴파일 에러
using namespace std;

int a,b;
bool arr[MAX][MAX];
bool v[MAX][MAX];

int bfs()
{
    queue<tuple<int,int,int>> q;
    q.push({0,0,1});
    v[0][0]=1;
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int d=get<2>(q.front());
        q.pop();
        if(x==a-1 and y==b-1){
            return d;
        }
        if(x-1>=0 and arr[x-1][y] and !v[x-1][y]){
            q.push({x-1,y,d+1});
            v[x-1][y]=1;
        }
        if(y-1>=0 and arr[x][y-1] and !v[x][y-1]){
            q.push({x,y-1,d+1});
            v[x][y-1]=1;
        }
        if(x+1<a and arr[x+1][y] and !v[x+1][y]){
            q.push({x+1,y,d+1});
            v[x+1][y]=1;
        }
        if(y+1<b and arr[x][y+1] and !v[x][y+1]){
            q.push({x,y+1,d+1});
            v[x][y+1]=1;
        }
    }
}

int main()
{
    //cin.tie(NULL);
    //cout.tie(NULL);
    //ios_base::sync_with_stdio(false);

    scanf("%d %d",&a,&b);

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%1d",&arr[i][j]);
        }
    }

    cout<<bfs();
}