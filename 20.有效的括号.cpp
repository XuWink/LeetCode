#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> stk;

        for (int i = 0; i < size; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (!stk.empty()) {
                    char left = stk.top();
                    stk.pop();
                    if (s[i] == ')' && left == '(') {
                        continue;
                    } else if (s[i] == ']' && left == '[') {
                        continue;
                    } else if (s[i] == '}' && left == '{') {
                        continue;
                    } else {
                        return false;
                    }
                } else {
                    stk.push(s[i]);
                }
            }
        }

        if (!stk.empty())
            return false;
        return true;
    }
};

int main() 
{
    Solution sol;

    string s = "()[]{}";
    bool result = sol.isValid(s);
    cout << "result = " << result << endl;
    return 0;
}

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

示例 4：
输入：s = "([])"
输出：true

*/