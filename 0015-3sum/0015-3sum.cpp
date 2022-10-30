class Solution {
private:
    vector<vector<int>> answer;
    
    void binarySearch(vector<int>&nums,int index){
        int n = nums.size();
        int low = index + 1,high = n - 1,sum = 0 - nums[index];
        while(low < high){
            int one = nums[low];
            int two = nums[high];
            if( one + two == sum){
                answer.push_back({one,two,nums[index]});
                while(low < high && nums[low] == nums[low + 1]){
                    low++;
                }
                while(low < high && nums[high] == nums[high - 1]){
                    high--;
                }
                low++,high--;
            }else if(one + two < sum){
                low++;
            }else{
                high--;
            }
        }
    }
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return answer;
        }
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n - 2; i++){
            if(i == 0 || (nums[i] != nums[i - 1])){
                binarySearch(nums,i);
            }
        }
        return answer;
    }
};