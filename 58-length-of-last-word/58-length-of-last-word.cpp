class Solution {
public:
    int lengthOfLastWord(string s) {
         int i = s.length() -1;
        int len = 0;
        while (i >=0 && s[i] == ' ') {
            i --;
        }
        while (i >=0) {
            if (s[i] == ' ') {
                break;
            }
            i --; len ++;
        }
        return len;
    
    }
};