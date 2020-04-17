n = int(input())
p = list(map(int, input().split()))

a = p[0]
del p[0]

total = sum(p) + a

coa = [1]
coaval = [a]

idx = 0
while sum(coaval) < 1 + int(total/2) and idx < len(p):
    if p[idx] <= int(a/2):
        coa.append(idx+2)
        coaval.append(p[idx])
    idx += 1
    

if idx == len(p) and sum(coaval) <  1 + int(total/2) :
    print(0)
else:
    
    print(len(coa))
    st = ""



    for i in coa:
        st += str(i) + " "
    print(st[:-1])


