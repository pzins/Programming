nb = input().split()
for i in range(int(nb[0])):
    tmp = input().split()
    c = int(tmp[0])
    sumi = int(tmp[1])
    if sumi < c:
        print(sumi)
    else:
        if sumi % c == 0:
            print(int((sumi/c)*(sumi/c)*c))
        else:
            sumic = pow(int(sumi/c), 2)
            sumicc = pow(1+int(sumi/c), 2)
            print(int(sumic * (c - sumi%c)) + (c - (c - sumi%c)) * sumicc)
            
        
