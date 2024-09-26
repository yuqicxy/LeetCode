/*
 * @lc app=leetcode id=1419 lang=cpp
 *
 * [1419] Minimum Number of Frogs Croaking
 */
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class StupidSolution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char,unsigned int> charCounter{
            {'c',0},{'r',0},{'o',0},{'a',0},{'k',0}
        };
        auto checkValidity = [&charCounter]()->bool{
            if(charCounter['c'] >= charCounter['r']
                && charCounter['r'] >= charCounter['o']
                && charCounter['o'] >= charCounter['a']
                && charCounter['a'] >= charCounter['k']
            )
                return true;
            return false;
        };
        int ans = 0;
        int count = 0;
        for (auto &&character : croakOfFrogs){
            charCounter[character]++;
            if(!checkValidity()) return -1;
            if(character == 'c'){
                count += 1;
            }else if(character == 'k'){
                ans = max(ans, count);
                count -= 1;
            }
        }
        return count == 0 ? ans : -1;
    }
};

// @lc code=start
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int count[5];
        for (auto &&i : count)
            i = 0;
        
        int maxFrogs = 0;
        int frog = 0;
        for (auto &&character : croakOfFrogs){
            auto n = string("croak").find(character);
            count[n]++;
            if(n == 0)
                maxFrogs = max(maxFrogs, ++frog);
            else if(--count[n-1] < 0)
                return -1;
            else if(n == 4)
                --frog;
        }
        return frog == 0 ? maxFrogs : -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minNumberOfFrogs("croakcroak") << endl; //1
    cout << s.minNumberOfFrogs("crcoakroak") << endl; //2
    cout << s.minNumberOfFrogs("croakcrook") << endl; //-1
    cout << s.minNumberOfFrogs("croakcroa") << endl; //-1

}

