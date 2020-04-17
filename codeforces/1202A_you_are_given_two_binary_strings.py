n = int(input())

for i in range(n):
    x = input()
    y = input()

    y_1 = len(y)-1
    yy = 0
    while y[y_1] == '0':
        y_1 -= 1
        yy += 1

    x_1 = len(x) - 1 - yy
    xx = 0
    while x[x_1] == '0':
        x_1 -= 1
        xx += 1


    
    print(xx)
    
