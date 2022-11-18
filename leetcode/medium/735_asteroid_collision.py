class Solution:
    def asteroidCollision(self, a: List[int]) -> List[int]:
        stop = True
        while True:
            idx = 0
            todel = []
            cont = False
            while idx < len(a) - 1:
                if a[idx] * a[idx+1] > 0:
                    idx += 1
                elif a[idx] > 0 and a[idx+1] < 0:
                    cont = True
                    if abs(a[idx]) > abs(a[idx+1]):
                        todel.append(idx+1)
                    elif abs(a[idx]) < abs(a[idx+1]):
                        todel.append(idx)
                    else:
                        todel.append(idx)
                        todel.append(idx+1)
                    #print(todel)
                    idx += 2
                else:
                    idx += 1
            for i in reversed(todel):
                a.pop(i)
                        
                
            if not cont:
                break
        return a
        
