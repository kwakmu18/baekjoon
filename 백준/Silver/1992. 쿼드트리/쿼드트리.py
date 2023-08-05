import sys
input = sys.stdin.readline

image = []
result = ""

def check(y,x,size):
    for i in range(y,y+size):
        for j in range(x,x+size):
            if image[y][x]!=image[i][j]: return False
    
    return True

def quadTree(y,x,size):
    global result
    if check(y,x,size):
        result+=image[y][x]
    else:
        size//=2
        result+="("
        quadTree(y,x,size)
        quadTree(y,x+size,size)
        quadTree(y+size,x,size)
        quadTree(y+size,x+size,size)
        result+=")"


N = int(input())
for _ in range(N):
    image.append(input().rstrip())

quadTree(0,0,N)

print(result)