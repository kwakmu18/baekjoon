x_n,y_n = map(float, input().split())

x_n1, y_n1 = 0,0
for _ in range(10000):
    x_n1 = (x_n+y_n)/2
    y_n1 = x_n*y_n/x_n1

    x_n,y_n = x_n1,y_n1
print("%.6f %.6f"%(x_n1, y_n1))