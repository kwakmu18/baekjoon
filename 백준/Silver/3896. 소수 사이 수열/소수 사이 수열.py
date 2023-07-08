import sys
input = sys.stdin.readline

SIZE = 1299710

prime = [True for _ in range(SIZE)]
prime[1] = False

for i in range(2,SIZE):
    if prime[i]:
        for j in range(i*2,SIZE,i):
            prime[j] = False

T = int(input())

for _ in range(T):
    k = int(input())
    if prime[k]:
        print(0)
        continue
    left, right = k,k
    while not prime[left]: left-=1
    while not prime[right]: right+=1
    print(right-left)