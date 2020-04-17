t=int(input())
for i in range(t):
    a,b,c,d = map(int, input().split())
    x, y, x1, y1, x2, y2 = map(int, input().split())
    if (a!=0 or b!=0) and (x==x1 and x==x2):
        print("No")
        continue
    if (c!=0 or d!=0) and (y==y1 and y==y2):
        print("No")
        continue
    if a-b > 0:
        if abs(a-b) > abs(x-x1):
            print("No")
            continue
    elif a-b < 0:
        if abs(a-b) > abs(x2-x):
            print("No")
            continue
    if c-d > 0:
        if abs(c-d) > abs(y-y1):
            print("No")
            continue
    elif c-d < 0:
        if abs(c-d) > abs(y2-y):
            print("No")
            continue
    print("Yes")
