class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        // Start from the end, find the last odd digit
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] ) % 2 == 1) {
                return num.substr(0, i + 1); // Include up to i
            }
        }
        return "";
    }
};
