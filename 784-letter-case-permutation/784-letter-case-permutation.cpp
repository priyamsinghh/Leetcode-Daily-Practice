class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        for (int i = 0; i < S.size(); i++) S[i] = tolower(S[i]);
        vector<string> ans;
        dfs(S, ans, 0, S.size());
        return ans;
    }
    void dfs(string S, vector<string> &ans, int i, int len) {
        if (i < len) {
            dfs(S, ans, i+1, len);
            if (isalpha(S[i])) {
                S[i] = toupper(S[i]);
                dfs(S, ans, i+1, len);
            }
        } else ans.push_back(S);
    }
};