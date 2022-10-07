class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int sum = 0;
        int idx = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                idx = i; 
            }
            else 
            {
                sum += arr[i];
            }
        }
        int total = (arr.size() + 1) * arr.size() / 2;
        
        return (total - sum);
    }
};