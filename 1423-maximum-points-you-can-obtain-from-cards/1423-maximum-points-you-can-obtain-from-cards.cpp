class Solution {
public:
    int maxScore(vector<int>& C, int K) {
        int total = 0;
        for (int i = 0; i < K; i++)
            total += C[i];
        int maxa= total;
        for (int i = K - 1, j = C.size() - 1; ~i; i--, j--)
        {
            total += C[j] - C[i];
            maxa = max(maxa, total);
        }
        return maxa;
    }
};