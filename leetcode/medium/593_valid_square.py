
class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        
        d12 = pow(pow(p1[0]-p2[0],2) + pow(p1[1]-p2[1],2), 0.5)
        d13 = pow(pow(p1[0]-p3[0],2) + pow(p1[1]-p3[1],2), 0.5)
        d14 = pow(pow(p1[0]-p4[0],2) + pow(p1[1]-p4[1],2), 0.5)
        d23 = pow(pow(p2[0]-p3[0],2) + pow(p2[1]-p3[1],2), 0.5)
        d24 = pow(pow(p2[0]-p4[0],2) + pow(p2[1]-p4[1],2), 0.5)
        d34 = pow(pow(p3[0]-p4[0],2) + pow(p3[1]-p4[1],2), 0.5)
        
        tmp = [d12, d13, d14, d23, d24, d34]
        tmp.sort()
        
        if tmp[0] == 0:
            return False
        
        if tmp[0] != tmp[1] or tmp[0] != tmp[2] or tmp[0] != tmp[3]:
            return False
        
        if tmp[4] != tmp[5]:
            return False
        
        if abs(tmp[4] - pow(2,0.5)*tmp[0]) > 0.0001:
            return False
        return True
    
