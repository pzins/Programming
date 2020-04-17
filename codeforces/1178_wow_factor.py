s = input()

os = []


for i in range(len(s)):
    if s[i] == 'o':
        os.append(i)


w = [0]

res = 0   
for idx in range(len(s)):
    if idx >= 1:
        if s[idx] == 'v' and s[idx-1] == 'v':
            w.append(w[idx-1]+1)
        else:
            w.append(w[idx-1])


last = w[-1]
for j in os:
    res += w[j] * (last - w[j])
print(res)
