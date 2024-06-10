/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        unsigned batchSize = numRows;
        if(numRows > 2)
            batchSize = numRows + (numRows - 2);
        unsigned len = s.length();
        for(int row = 0; row < numRows; ++row){
            unsigned index = (unsigned)row;
            while(index < len){
                result.push_back(s[index]);
                if(row > 0 && row < numRows - 1){
                    if(index + (batchSize - 2*row) < len)
                        result.push_back(s[index + (batchSize - 2*row)]);
                }

                index += batchSize;
            }
        }

        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::cout<<s.convert("PAYPALISHIRING",4);
    return 0;
}