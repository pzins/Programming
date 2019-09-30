nb = input().split()

l = int(nb[0])
r = int(nb[1])

if l == r:
    l -= 1

finished = False

for n in range(l+1, r+1):
    d = set()

    s = str(n)
    good = True
    for i in s:
        if i in d:
            good = False
            break
        d.add(i)
    if good:
        print(n)
        finished = True
        break
if not finished:
    print(-1)

