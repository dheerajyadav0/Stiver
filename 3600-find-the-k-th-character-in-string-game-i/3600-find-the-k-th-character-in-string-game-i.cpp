class Solution {
public:
    char kthCharacter(int k) {
        int length = 1;
        while (length < k) {length *= 2; }
        char ch = 'a';
        while (length > 1) {
            length /= 2;
            if (k > length) { k -= length;
                ch = (ch - 'a' + 1) % 26 + 'a'; }
        }
        return ch;
    }
};