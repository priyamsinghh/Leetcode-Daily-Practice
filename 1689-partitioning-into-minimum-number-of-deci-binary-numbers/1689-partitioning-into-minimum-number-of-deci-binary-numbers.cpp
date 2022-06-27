class Solution {
public:
    int minPartitions(string n) {
        int s=n.length();
        int m=0;
        for(auto i:n)
        {
            int x = i-'0';
            m=max(x,m);
        }
        return m;
    }
};