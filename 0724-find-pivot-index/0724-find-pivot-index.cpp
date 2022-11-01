class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int ls=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(sum-ls-nums[i]==ls)
                return i;
            ls+=nums[i];
        }
        return -1;
    }
};