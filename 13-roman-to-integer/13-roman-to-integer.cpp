class Solution {
public:
    int romanToInt(string s) {
        map<char, int> characterMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int length = s.length();

        if(length == 0) {
            return 0;
        }

        if(length == 1){
            return characterMap[s[0]];
        }

        int sum = characterMap[s[length - 1]];
        for(int i = length - 2; i >= 0; i--){
            if(characterMap[s[i]] < characterMap[s[i+1]]){
                sum -= characterMap[s[i]];
            } else {
                sum += characterMap[s[i]];
            }
        }

        return sum;
    }
};