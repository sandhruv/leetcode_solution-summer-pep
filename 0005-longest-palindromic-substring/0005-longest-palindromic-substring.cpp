class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLength = 0;

        for (int center = 0; center < static_cast<int>(s.size()); ++center) {
            for (int offset : {0, 1}) {
                int left = center;
                int right = center + offset;

                while (left >= 0 && right < static_cast<int>(s.size()) &&
                       s[left] == s[right]) {
                    int length = right - left + 1;
                    if (length > maxLength) {
                        start = left;
                        maxLength = length;
                    }
                    --left;
                    ++right;
                       }
            }
        }

        return s.substr(start, maxLength);
    }
};