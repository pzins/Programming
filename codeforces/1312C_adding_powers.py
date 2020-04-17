def dec(a, k):
    res = []
    while(a >= k):
        rest = a%k
        res.append(rest)
        a = a // k
        if rest > 1:
            return [], False
    if a > 1:
        return [], False
    res.append(a)
    return res, True
 
t=int(input())
for i in range(t):
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    ok=  True
    m = 0
    r = {}
    ma = 0
    for i in a:
        if i == 0:
            continue
        tmp, o = dec(i, k)
        #print(i, k, o, tmp)
        if o == False:
            ok = False
            break
        for idx, kk in enumerate(tmp):
            if kk == 1:
                if idx in r:
                    ok = False
                    break
                else:
                    r[idx] = 1
                
    
    if ok:
        print("YES")
    else:
        print("NO")
