#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
		vector<vector<string>> result;
		
		unordered_map<string, vector<string>> umap;
		
		for(string str : strs){
			string temp = str;
			std::sort(temp.begin(), temp.end());
			auto it = umap.find(temp);
			if(it != umap.end()){
				umap[temp].emplace_back(str);
			}else{
				umap[temp] = {str};
			}
		}
		
		for(auto item : umap){
			result.emplace_back(item.second);
		}
		
		return result;
    }
};

int main(){
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution sol;
	vector<vector<string>> result = sol.groupAnagrams(strs);
	for(vector<string> item : result){
		for(string str : item){
			std::cout<<str<<" ";
		}
		std::cout<<"\n";
	}
}


/*

给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

示例 2:
输入: strs = [""]
输出: [[""]]

示例 3:
输入: strs = ["a"]
输出: [["a"]]

*/