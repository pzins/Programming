class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        double w = 0;
        double h = 0;
        double total = double((C-A) * (D-B)) + double((G-E) * (H-F));
        if(A <= C && C <= E && E <= G)
        {
            return total;
        }
        else if(A <= E && E <= C && C <= G)
        {
            w = C - E;
        }
        else if(A <= E && E <= G && G <= C)
        {
            w = G - E;
        }
        else if(E <= G && G <= A && A <= C)
        {
            return total;
        }
        else if(E <= A && A <= G && G <= C)
        {
            w = G - A;
        }
        else if(E <= A && A <= C && C <= G)
        {
            w = C - A;
        }
        
        if(B <= D && D <= F && F <= H)
        {
            return total;
        }
        else if(B <= F && F <= D && D <= H)
        {
            h = D - F;
        }
        else if(B <= F && F <= H && H <= D)
        {
            h = H - F;
        }
        else if(F <= H && H <= B && B <= D)
        {
            return total;         
        }
        else if(F <= B && B <= H && H <= D)
        {
            h = H - B;
        }
        else if(F <= B && B <= D && D <= H)
        {
            h = D - B;
        }
        return total - h * w;
    }
        
};
