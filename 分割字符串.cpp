#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    void my_split(const string& str, char delim, vector<string>& out){
        if(str.empty()){
            return;
        }
        out.clear();
        int loc = 0;
        int next_loc = 0;
        string temp = str;
        while((next_loc = temp.find(delim, loc)) != string::npos){  //!= std::string::npos
            out.push_back(temp.substr(loc, next_loc - loc));
            loc = next_loc + 1;
        }

        // 添加最后一个子字符串
        if (loc < temp.size()) {
            out.push_back(temp.substr(loc));
        }
    }
};

int main(int argc, char** argv){
    Solution sol;
    string str = "Hello World!";
    char delim = ' ';
    vector<string> result;
    sol.my_split(str, delim, result);

    for(string item : result){
        std::cout << item << std::endl;
    }
    
    return 0;
}