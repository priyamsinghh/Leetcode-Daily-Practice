class Solution
{

public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int type;
        if ("type" == ruleKey)
        {

            type = 0;
        }
        else if ("color" == ruleKey)
        {

            type = 1;
        }
        else
        {
            type = 2;
        }
        int ans = 0;
        for (vector<string> &item : items)
        {

            if (ruleValue == item[type])
            {

                ++ans;
            }
        }
        return ans;
    }
};