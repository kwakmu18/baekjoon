noans=[]
for i in range(1,10001):
    num=0
    for j in str(i):
        num+=int(j)
    new=int(num+i)
    if new in noans:continue
    else:noans.append(new)
for i in range(1,10001):
    if i not in noans:
        print(i)