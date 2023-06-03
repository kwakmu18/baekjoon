from collections import deque
import sys

input = sys.stdin.readline

def bfs():
    global cost
    queue = deque([[0,0,1]])
    while queue:
        now = queue.popleft()
        nowY,nowX,nowCost=now[0],now[1],now[2]
        if cost[nowY][nowX]<nowCost:continue

        for dy,dx in pos:
            newY, newX, newCost = nowY+dy, nowX+dx, nowCost+1
            if newY>=0 and newX>=0 and newY<n and newX<m and maze[newY][newX]==1:
                if cost[newY][newX]>newCost:
                    cost[newY][newX]=newCost
                    queue.append([newY,newX,newCost])

n,m = map(int, input().split())

maze = [[0 for _ in range(m)] for _ in range(n)]
cost = [[987654321 for _ in range(m)] for _ in range(n)]
cost[0][0]=1
for i in range(n):
    line = input().rstrip()
    for j in range(m):
        maze[i][j] = int(line[j])

pos = [[-1,0],[1,0],[0,-1],[0,1]]

bfs()

print(cost[n-1][m-1])