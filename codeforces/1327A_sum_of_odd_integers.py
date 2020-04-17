m=int(input())
for i in range(m):
    n,k=input().split()
    n=int(n)
    k=int(k)
    if n % 2 == 0:
        if k % 2 == 0:
            s = k * (1 + (1+2*(k-1)))/2
            if s <= n:
                print("YES")
            else:
                print("NO")
        else:
            print("NO")
    else:
        if k % 2 == 1:
            s = k * (1 + (1+2*(k-1)))/2
            if s <= n:
                print("YES")
            else:
                print("NO")
        else:
            print("NO")
