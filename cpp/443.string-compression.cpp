/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */
#include <vector>
#include <string>

using namespace std;

class StupidSolution {
public:
    int compress(vector<char>& chars) {
        size_t N = chars.size();
        char prev = chars.front();
        string result;
        result.push_back(prev);
        int count = 1;
        for(size_t i = 1; i < N; ++i)
        {
            if(chars[i] == prev){
                count++;
            }
            else{
                if(count > 1)
                    result += to_string(count);
                prev = chars[i];
                result.push_back(prev);
                count = 1;
            }
        }
        if(count > 1)
            result += to_string(count);
        
        chars.clear();
        for (auto &&c : result)
            chars.push_back(c);
        
        return (int)result.length();
    }
};

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        size_t N = chars.size();
        int i = 0;
        for(int j = 1,count = 1; j <= N; ++j,++count){
            if(j == chars.size() || chars[j] != chars[j - 1]){
                chars[i++] = chars[j - 1];
                if(count > 1){
                    for (auto &&c : to_string(count))
                        chars[i++] = c;
                }
                count = 0;
            }
        }
        chars.erase(chars.begin() + i,chars.end());
        return i;
    }
};
// @lc code=end
#include <iostream>

void print(const vector<char>& chars){
    for (auto &&i : chars)
        cout << i << " ";
    cout << endl;
}

int main(){
   
    vector<char> chars{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    Solution s;
    cout << s.compress(chars) << endl;  //4
    print(chars);
    chars = {'a','a','b','b','c','c','c'};
    cout << s.compress(chars) << endl;  //6
    print(chars);

    chars = {'a','a','b','b','c','c','c'}; 
    cout << s.compress(chars) << endl;  //6
    print(chars);

    chars = {'a','a'}; 
    cout << s.compress(chars) << endl;  //2
    print(chars);

    return 0;
}
