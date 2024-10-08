/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */
#include <vector>
#include <stack>
#include <tuple>
#include <iostream>
using namespace std;

class SolutionQiStack {
public:
    /**
     * @brief 
     * 
     * @param temperatures 
     * @return vector<int> 
     */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size(),0);
        stack<size_t> waitingList;
        waitingList.emplace(0);
        for(size_t i = 1; i < temperatures.size(); ++i){
            while(!waitingList.empty()){
                size_t indexOfMin = 0;
                indexOfMin = waitingList.top();
                if(temperatures[indexOfMin] < temperatures[i]){
                    results[indexOfMin] = (int)(i - indexOfMin);
                    waitingList.pop();
                }else{
                    break;
                }
            }
            waitingList.emplace(i);
        }
        return results;
    }
};

// @lc code=start
class Solution {
public:
    /**
     * @brief 
     * 
     * @param temperatures 
     * @return vector<int> 
     */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> results(len,0);
        if(len < 2)
            return results;
        for(int i = len - 2; i >= 0; --i){
            for(int j = i+1; j < len; j += results[j]){
                if(temperatures[i] < temperatures[j]){
                    results[i] = j - i;
                    break;
                }else if(results[j] == 0)
                    break;
            }
        }
        return results;
    }
};
// @lc code=end
ostream& operator<<(ostream&ss, vector<int> vec){
    for(auto val : vec){
        ss<< val << " ";
    }
    return ss;
}

int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution s;
    cout<<s.dailyTemperatures(temperatures)<<endl;
    temperatures = {30,40,50,60};
    cout<<s.dailyTemperatures(temperatures)<<endl;
    temperatures = {90,60,30};
    cout<<s.dailyTemperatures(temperatures)<<endl;
}

