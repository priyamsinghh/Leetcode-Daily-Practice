class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
        {
            return true;
        }
        for(int i=0;i<=30;i++)
        {
            int ans=pow(2,i);
            if(n==ans)
            {
                return true;
            }
        }
        return false;
    }
};