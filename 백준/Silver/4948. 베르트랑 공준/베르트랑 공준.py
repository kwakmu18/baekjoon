import sys
input = sys.stdin.readline

SIZE = 123456*2+1

prime = [True for _ in range(SIZE)]
prime[1] = False

for i in range(2,SIZE):
    if prime[i]:
        for j in range(i*2,SIZE,i):
            prime[j] = False

while True:
    cnt = 0
    n = int(input())
    if n==0:break

    for i in range(n+1, 2*n+1):
        if prime[i]:cnt+=1
    
    print(cnt)