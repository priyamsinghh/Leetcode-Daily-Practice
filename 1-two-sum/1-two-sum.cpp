class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,x1,x2;
        vector<int>ans,st;
        st=nums;
        sort(st.begin(),st.end());
        while(i<j)
        {
            if((st[i]+st[j])==target){
                 x1 = st[i];
                 x2 = st[j];
                break;
            }
            else if((st[i]+st[j])>target)
                    j--;
            else
                    i++;
                    
        }
        for(int i=0;i<nums.size();++i){

        	if(nums[i]==x1)
            	    ans.emplace_back(i);
        	else if(nums[i]==x2)
            	    ans.emplace_back(i);
    	}
        return ans;
             
        
    }
};