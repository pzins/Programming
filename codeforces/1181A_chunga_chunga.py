inpt = input().split()
a = int(inpt[0])
b = int(inpt[1])
price = int(inpt[2])
 
nb = 0
nb += a // price
nb += b // price
restA = a % price
restB = b % price
res = 0
if restA + restB >= price:
    nb += 1
    if restA >= restB:
        res = price - restA
    else:
        res = price - restB
print(int(nb), res)
