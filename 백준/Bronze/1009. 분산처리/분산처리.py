import sys
l2=[2,4,8,6]
l3=[3,9,7,1]
l4=[4,6]
l7=[7,9,3,1]
l8=[8,4,2,6]
l9=[9,1]
a=int(sys.stdin.readline())
for i in range(0,a):
    a,b=map(int, sys.stdin.readline().split())
    if a%10==0:print(10)
    elif a%10==1:print(1)
    elif a%10==2:print(l2[b%4-1])
    elif a%10==3:print(l3[b%4-1])
    elif a%10==4:print(l4[b%2-1])
    elif a%10==5:print(5)
    elif a%10==6:print(6)
    elif a%10==7:print(l7[b%4-1])
    elif a%10==8:print(l8[b%4-1])
    elif a%10==9:print(l9[b%2-1])
