n = int(input())
s = input()

nb = 0
for i in s:
    if i == '1':
        nb += 1
    else:
        nb -= 1
    
if nb != 0:
    print("1")
    print(s)
    
else:
    print(2)
    print(s[0], s[1:])

