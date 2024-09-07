/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */
#include<iostream>
using namespace std;

unsigned pick  = 0;

int guess(int num){
    if(num > pick)
        return -1;
    else if(num < pick)
        return 1;
    return 0;
}
// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int upperBound = n;
        int lowerBound = 1;
        bool found = false; 
        int guessVal = 0;
        while(!found){
            guessVal = floor((upperBound - lowerBound)/2.0) + lowerBound;
            switch(guess(guessVal)){
                case -1:
                    upperBound = guessVal - 1;
                    break;
                case 1:
                    lowerBound = guessVal + 1;
                    break;
                case 0:
                    found = true;
            }   
        }
        return guessVal;
    }
};
// @lc code=end

int main(){
    Solution s;
    pick = 6;
    cout<<s.guessNumber(10)<<endl;
    pick = 1;
    cout<<s.guessNumber(1)<<endl;
    pick = (1<<31) - 1;
    cout<<s.guessNumber(INT_MAX)<<endl;
}

