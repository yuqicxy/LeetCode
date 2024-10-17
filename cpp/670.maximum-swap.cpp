/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */
#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string strNum = to_string(num);
        int N = (int)strNum.size();
        int maxId = N - 1;
        int xi = 0, yi = 0;
        //backward iter to find max
        // if curr > max:
        //      update max;
        // elif curr < max:
        //      str[curr] and str[max] could be a candidate swap
        
        for(int i = N - 1; i >= 0; --i){
            if(strNum[i] > strNum[maxId]){
                maxId = i;
            }else if(strNum[i] < strNum[maxId]){
                xi = i;
                yi = maxId;
            }
        }

        swap(strNum[xi], strNum[yi]); 

        int ans = stoi(strNum);
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.maximumSwap(2736) << endl; //7236
    cout << s.maximumSwap(9973) << endl; //9973
    cout << s.maximumSwap(98368) << endl; //98863
    cout << s.maximumSwap(1993) << endl; //9913
}