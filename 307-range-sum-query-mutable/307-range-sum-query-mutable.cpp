class NumArray {
public:
    vector<int> blocks;
    vector<int> nums;
    int len;
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
        if(nums.size() == 0){
            this->len = 0;
        }else{
            this->len = ceil(nums.size()/sqrt(nums.size()));
        }
        this->blocks = vector<int>(len, 0);
        for(int i = 0; i < nums.size(); i++){
            blocks[i/len] += nums[i];
        }
    }
    
    void update(int i, int val) {
        int blockId = i/len;
        blocks[blockId] += (val - nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        
        int startBlock = i/len, endBlock = j/len;
        
        if(startBlock == endBlock){
            for(int k = i; k <= j; k++){
                sum += nums[k];
            }
        }else{
            for(int k = i; k <= (startBlock+1)*len -1; k++){
                sum += nums[k];
            }
            for(int k = startBlock+1; k <= endBlock-1; k++){
                sum += blocks[k];
            }
            for(int k = endBlock*len; k <= j; k++){
                sum += nums[k];
            }
        }
        
        return sum;
    }
};