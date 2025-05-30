#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int s_len = s.length();
        int p_len = p.length();
        if (p_len > s_len) return result;

        int count[26] = { 0 };
        for (int i = 0; i < p_len; ++i) {
            count[p[i] - 'a'] += 1;
        }

        for (int i = 0; i <= s_len - p_len + 1; ++i) {
            int temp_count[26] = { 0 };
            string temp_str = s.substr(i, p_len);
            for (int j = 0; j < p_len; ++j) {
                temp_count[temp_str[j] - 'a'] += 1;
            }

            if ( count == temp_count) {
                result.emplace_back(i);
            }
        }

        return result;
    }
};

/*
解决思路
这是一个经典的滑动窗口问题，我们可以用以下步骤解决：
使用一个长度为26的数组记录模式串p中每个字符的出现次数
使用滑动窗口在s中移动，维护一个与p等长的窗口
对每个窗口，检查其字符频率是否与p相同
如果相同，则将窗口起始位置加入结果数组

给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
*/