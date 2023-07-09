import sys
input = sys.stdin.readline
#sys.set_int_max_str_digits(1000000)

n = int(input())
ans = 1
for i in range(1,n+1):
    ans*=i

print(ans)
