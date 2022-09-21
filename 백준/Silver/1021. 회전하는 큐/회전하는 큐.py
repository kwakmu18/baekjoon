import sys
from collections import deque
input=sys.stdin.readline

n,m=map(int, input().split())

num=deque([n for n in range(1,n+1)])
index=[n for n in range(0,n)]
search=list(map(int, input().split()))

cnt=0

for i in search:
    if (num[0]==i): num.popleft()
    else:
        size, index=len(num), 0
        for j in range(1, n):
            if num[j]==i: index=j; break
        if j>abs(size-j):
            while (num[0]!=i): num.appendleft(num.pop()); cnt+=1
            num.popleft()
        else:
            while (num[0]!=i): num.append(num.popleft()); cnt+=1
            num.popleft()

print(cnt)
