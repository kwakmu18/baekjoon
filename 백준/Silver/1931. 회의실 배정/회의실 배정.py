import sys
input=sys.stdin.readline

n=int(input())

meet=[]

for _ in range(n):
    meet.append(list(map(int, input().split())))

meet.sort(key=lambda x:(x[1],x[0]))


ans, end, start=[meet[0]], meet[0][1], meet[0][0]

for i in meet[1:]:
    if end<=i[0]:
        ans.append(i)
        end=i[1]

print(len(ans))