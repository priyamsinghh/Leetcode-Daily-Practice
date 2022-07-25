class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        int m=1;
        for(int i=0;i<32;i++)
        {
            if((n&m))
            {
                count++;
            }
            n>>=1;
        }
        return count;
    }
};