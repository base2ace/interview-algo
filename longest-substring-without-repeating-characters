
Given a string s, find the length of the longest substring without repeating characters.
 
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.


class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0;
        int right = 0;
        set<char> seen;
        int max = 0;

        while(right < s.size())
        {
            if (seen.find(s[right]) == seen.end())
            {
                seen.insert(s[right]);
                max = std::max(right-left + 1, max);
                right++;
            }
            else
            {
                while(s[left] != s[right])
                {
                    seen.erase(s[left]);
                    left++;
                }
                seen.erase(s[right]);
                left++;
            }
        }
        return max;

    }
};
