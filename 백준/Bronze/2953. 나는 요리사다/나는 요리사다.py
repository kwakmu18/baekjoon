a=list(map(int, input().split()))
b=list(map(int, input().split()))
c=list(map(int, input().split()))
d=list(map(int, input().split()))
e=list(map(int, input().split()))
l=[0,0,0,0,0]
l[0],l[1],l[2],l[3],l[4]=sum(a),sum(b),sum(c),sum(d),sum(e)
f=max(l)
for i in range(5):
    if f==l[i]:
        print(i+1,l[i])