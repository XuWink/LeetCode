#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // 字符集用于记录当前窗口中的字符
        std::unordered_set<char> char_set;
        int max_length = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // 当遇到重复字符时，左指针右移直到窗口中没有重复字符
            while (char_set.find(s[right]) != char_set.end()) {
                char_set.erase(s[left]);
                left++;
            }
            
            // 将当前字符加入集合
            char_set.insert(s[right]);
            
            // 更新最大长度
            max_length = std::max(max_length, right - left + 1);
        }
        
        return max_length;
    }
};

/*
解题思路
我们可以使用滑动窗口的方法来解决这个问题：
维护一个窗口，使得窗口内的字符都不重复
使用一个集合或哈希表来记录当前窗口中的字符
右指针不断向右扩展窗口，当遇到重复字符时，左指针向右移动直到窗口中不再包含重复字符
在这个过程中，不断更新最大长度


给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3

解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/