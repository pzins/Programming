p = list(map(int, input().split()))
w = p[0]
h = p[1]

res = 4 * pow(2,w-1) * pow(2, h-1)

print(res % 998244353)
        
