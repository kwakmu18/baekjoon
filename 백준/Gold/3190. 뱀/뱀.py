import sys
from collections import deque
input=sys.stdin.readline

#일반 바닥은 0, 사과는 1, 뱀이 위치한 칸은 -1

n=int(input())
board=[[0]*n for _ in range(n)]

apple_cnt=int(input())
for _ in range(apple_cnt):
    x,y=map(int, input().split())
    board[x-1][y-1]=1

movement_cnt=int(input())
movement=[]
for _ in range(movement_cnt):
    movement.append(input().split())
movement.append([9999, 'N'])
head, tail=[0,0], [0,0]
board[0][0]=-1
time=0

snake=deque([[0,0]])


direction=[[0,1], [1,0], [0,-1], [-1,0]]
dirindex=0

flag=False

for mov in movement:
    for cnt in range(int(mov[0])-time):
        time+=1
        now=snake.pop()
        newx=now[0]+direction[dirindex][0]; newy=now[1]+direction[dirindex][1]
        if newx<0 or newy<0 or newx>=n or newy>=n:
            flag=True; break
        if board[newx][newy]==1:
            snake.append(now); snake.append([newx, newy])
            board[newx][newy]=-1
            board[now[0]][now[1]]=-1
        elif board[newx][newy]==-1:
            flag=True
            break
        else:
            if len(snake)==0:
                    board[now[0]][now[1]]=0
                    snake.append([newx, newy])
            else:
                snake.append(now); snake.append([newx, newy])
                now=snake.popleft()
                board[now[0]][now[1]]=0
            board[newx][newy]=-1
    if flag:break
    if mov[1]=='L':
        if dirindex==0:dirindex=3
        else: dirindex-=1
    elif mov[1]=='D':
        if dirindex==3: dirindex=0
        else: dirindex+=1    


print(time)