import sys
input = sys.stdin.readline

N = int(input())
X,Y = set(),set()
for _ in range(N):
    x,y=map(int, input().split())
    X.add(x)
    Y.add(y)

if len(X)==1 or len(Y)==0:
    print(0)
else:
    print((max(X)-min(X))*(max(Y)-min(Y)))