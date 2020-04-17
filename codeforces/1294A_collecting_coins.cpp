n=int(input())
for i in range(n):
    v = list(map(int, input().split()))
    if sum(v) % 3 != 0:
        print("NO")
    else:
        nb = sum(v) / 3
        if nb < v[0] or nb < v[1] or nb < v[2]:
            print("NO")
        else:
            print("YES")
