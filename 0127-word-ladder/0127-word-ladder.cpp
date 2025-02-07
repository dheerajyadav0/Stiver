class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end()) return 0;

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

           
            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i]; // Store original character
                
                for (char c = 'a'; c <= 'z'; c++) {
                    if (word[i] == c) continue; // Skip replacing with the same letter

                    word[i] = c;
                    
                    if (st.find(word) != st.end()) {
                        q.push({word, steps + 1});
                        st.erase(word); // Remove to prevent revisiting
                    }
                }

                word[i] = original; // Restore original character
            }
        }

        return 0; 
    }
};
