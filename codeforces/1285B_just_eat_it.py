
t = int(input())
for i in range(t):
    n = int(input())
    t = list(map(int, input().split()))
    s = 0
    p = 0
    no = False
    for i in range(len(t)):
        s += t[i]
        p += t[len(t)-i-1]
        if s <= 0 or p <= 0:
            no = True
            break
    if no:
        print("NO")
    else:
        print("YES")
