/*
 * @lc app=leetcode id=2601 lang=cpp
 *
 * [2601] Prime Subtraction Operation
 */
#include <vector>
#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

// @lc code=start
const int MAX = 1001;

vector<int> primes{0};

int init = [](){
    array<bool, MAX> isPrime;
    isPrime.fill(true);
    for(int i = 2; i < MAX; ++i){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i * i; j < MAX; j += i){
                isPrime[j] = false;
            }
        }
    }
    return 0;  
}();

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int prev = 0;
        for(auto num : nums){
            int newNum = num - *(--lower_bound(begin(primes) + 1, end(primes), num - prev));
            if(newNum <= prev)
                return false;
            prev = newNum;
        }
        return true;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << boolalpha;
    
    vector nums{4,9,6,10};
    cout << s.primeSubOperation(nums) << endl;

    nums = {6,8,11,12};
    cout << s.primeSubOperation(nums) << endl;

    nums = {5,8,3};
    cout << s.primeSubOperation(nums) << endl;

    return 0;
}

