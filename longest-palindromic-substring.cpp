Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.



class Solution {
public:

std::string longestPalindrome(const std::string& s) {
    int n = s.length();
    if (n == 0)
        return "";

    std::string modified = "#";
    for (char c : s) {
        modified += c;
        modified += "#";
    }

    n = modified.length();
    int maxRight = 0, center = 0;
    int maxLen = 0, start = 0;
    std::vector<int> palindromeLength(n, 0);

    for (int i = 0; i < n; ++i) {
        if (i < maxRight) {
            int mirror = 2 * center - i;
            palindromeLength[i] = std::min(maxRight - i, palindromeLength[mirror]);
        }

        int left = i - (palindromeLength[i] + 1);
        int right = i + (palindromeLength[i] + 1);

        while (left >= 0 && right < n && modified[left] == modified[right]) {
            palindromeLength[i]++;
            left--;
            right++;
        }

        if (i + palindromeLength[i] > maxRight) {
            center = i;
            maxRight = i + palindromeLength[i];
            if (palindromeLength[i] > maxLen) {
                start = (i - palindromeLength[i]) / 2;
                maxLen = palindromeLength[i];
            }
        }
    }

    return s.substr(start, maxLen);
}

};
