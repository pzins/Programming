p = list(map(int, input().split()))
n = p[0]
x = p[1]
y = p[2]
d = list(map(int, input().split()))

for i in range(len(d)):
    good = True
    for j in range(i-x, i+y+1):
        if j >= 0 and j < len(d) and j != i and d[j] <= d[i]:
            good = False
            break
    if good:
        print(i+1)
        break
