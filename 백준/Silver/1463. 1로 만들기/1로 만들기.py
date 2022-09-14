import sys

input=sys.stdin.readline

mincnt=[0]*1000002

mincnt[1]=0; mincnt[2]=1; mincnt[3]=1;

tmp=2
while tmp<=999999:
    if tmp*2<=1000000:
        if mincnt[tmp*2]==0:mincnt[tmp*2]=mincnt[tmp]+1
        else:mincnt[tmp*2]=min(mincnt[tmp*2], mincnt[tmp]+1)

        if mincnt[tmp*2+1]==0:mincnt[tmp*2+1]=mincnt[tmp]+2
        else:mincnt[tmp*2+1]=min(mincnt[tmp*2+1], mincnt[tmp]+2)

        if tmp*3<=1000000:
            if mincnt[tmp*3]==0:mincnt[tmp*3]=mincnt[tmp]+1
            else:mincnt[tmp*3]=min(mincnt[tmp*3], mincnt[tmp]+1)

            if mincnt[tmp*3+1]==0:mincnt[tmp*3+1]=mincnt[tmp]+2
            else:mincnt[tmp*3+1]=min(mincnt[tmp*3+1], mincnt[tmp]+2)

    if mincnt[tmp+1]==0:mincnt[tmp+1]=mincnt[tmp]+1
    else:mincnt[tmp+1]=min(mincnt[tmp+1], mincnt[tmp]+1)
    
    tmp+=1

print(mincnt[int(input())])