class Solution {
public:
    double angleClock(int h, int m) {
        float angle_h = (h % 12) * 360 / 12 + float(m % 60) / 60 * 360 / 12;
        float angle_m = (m % 60) * 360 / 60;
        cout << angle_h << " " << angle_m << endl;
        float res = abs(angle_h - angle_m);
        if (res > 180) return 360 - res;
        return res;
    }
};
