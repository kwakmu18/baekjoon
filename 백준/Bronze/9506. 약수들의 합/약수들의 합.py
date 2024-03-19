import sys
input = sys.stdin.readline

while True:
    n = int(input())
    if n==-1: break
    l = []
    for i in range(1,n//2+1):
        if n%i==0: l.append(i)
    
    s = f"{n}"
    if sum(l)==n:
        s += f" = {l[0]}"
        for num in l[1:]:
            s += f" + {num}"
    else:
        s += " is NOT perfect."
    print(s)