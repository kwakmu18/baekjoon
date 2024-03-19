import sys
input = sys.stdin.readline

a,b,c = map(int, input().split())
ans = 0
for i in range(1,a+1):
    for j in range(1,b+1):
        for k in range(1,c+1):
            l = sorted([i,j,k])
            if l[2] < l[0] + l[1]:ans = sum(l)
print(ans)