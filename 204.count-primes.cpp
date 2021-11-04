/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    // int countPrimes(int n) {
    //     if(n < 2)
    //         return 0;
    //     int count = 0;
    //     vector<bool> isPrime(n,true);
    //     for(int i = 2; i < n; ++i){
    //         if(!isPrime[i])
    //             continue;
    //         count++;
    //         for(int j = 2; i * j < n; j++){
    //             isPrime[i * j] = false;
    //         }
    //     }
    //     return count;
    // }

    int countPrimes(int n) {
        if(n < 2)
            return 0;
        int squareOfN = sqrt(n) + 1;
        vector<bool> isPrime(n,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i < squareOfN; ++i){
            if(!isPrime[i])
                continue;
            for(int j = i * i ; j < n; j += i){
                isPrime[j] = false;
            }
        }
        int sum = 0;
        return accumulate(isPrime.begin(),isPrime.end(),sum);
    }
};
// @lc code=end