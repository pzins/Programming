import math
n = int(input())
if n < 4:
    print(1)
# elif n == 4:
#     res = 3 * (1/3)**4
#     print(1-res)
elif n == 5:
    print(1-80/4**5)
else:
    res = 0
    for k in range(2, int(n*0.5)+1):
        f = math.factorial(n)/(math.factorial(k)*math.factorial(n-k))
        if k == n-k:
            f *= 0.5
        f2 = (n-k-1)**(n-k)
        res += f * f2 * ((k-1)/(n-1))**k * (((n-k)-1)/(n-1))**(n-k)
    print(1-res)