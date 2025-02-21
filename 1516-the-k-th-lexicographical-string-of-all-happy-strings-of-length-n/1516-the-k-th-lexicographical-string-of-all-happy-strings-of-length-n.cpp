class Solution {
public:
    
    void happy(int n, int k, int &count, string s, string &result) {
     
        if (s.length() == n) {
            count++;
           
            if (count == k) {
                result = s;
            }
            return;
        }

        
        for (char ch = 'a'; ch <= 'c'; ch++) {
           
            if (s.empty() || s.back() != ch) {
                s.push_back(ch);
                happy(n, k, count, s, result);
                s.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string result = "";
        int count = 0;
        happy(n, k, count, "", result);
        return result;
    }
};