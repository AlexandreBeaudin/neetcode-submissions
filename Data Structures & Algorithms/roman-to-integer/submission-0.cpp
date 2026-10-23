class Solution {
public:
// You just need to convert either 1 OR 2 characters into a number to get the answer.
    int romanToInt(string s) {
        int ans = 0;
        // All 1 Character Instances:
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        // Instances of 2 Characters:
        // {IV, 4}, {IX, 9}, {XL, 40}, {XC, 90}, {CD, 400}, {CM, 900}

        int N = s.size();
        for (int i = 0; i < N; i++) {
            int curr = roman[s[i]];
            if (i+1 < N && curr < roman[s[i+1]]) {
                ans -= curr;  // substract the smaller left numeral and then adding in the next round will result in the correct final sum
            } else {
                ans += curr;
            }
        }
        return ans;
    }
};