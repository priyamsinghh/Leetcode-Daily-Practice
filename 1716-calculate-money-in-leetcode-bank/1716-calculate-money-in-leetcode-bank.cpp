class Solution {
public:
    int totalMoney(int n) {
        int mon = 0;
        int cur = 0;
        int ret = 0;
        for(int i = 0; i < n; ++i, ++cur) {
            if(i % 7 == 0) {
                mon++;
                cur = mon;
            }
            ret += cur;
        }
        return ret;
    }
};