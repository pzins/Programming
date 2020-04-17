l = int(input())
nb = input()
nbr = str(nb)
 
mini = 0
 
mid = l // 2
if nbr[mid] != '0':
    tmp = int(nbr[:mid]) + int(nbr[mid:])
    if mini == 0 or mini > tmp:
        mini = tmp
 
cnt = 1
while mid + cnt < l:
    if nbr[mid + cnt] != '0':
        tmp = int(nbr[:mid+cnt]) + int(nbr[mid+cnt:])
        if mini == 0 or mini > tmp:
            mini = tmp
        break
    else:
        cnt += 1
 
 
cnt = 1
while mid - cnt > 0:
    if nbr[mid - cnt] != '0':
        tmp = int(nbr[:mid-cnt]) + int(nbr[mid-cnt:])
        if mini == 0 or mini > tmp:
            mini = tmp
        break
    else:
        cnt += 1
 
print(mini)
