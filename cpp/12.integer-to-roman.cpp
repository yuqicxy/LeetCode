/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include <string>
#include <map>
using namespace std;

class StupidSolution {
public:
    string intToRoman(int num) {
        map<unsigned, char> symbols{
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };

        map<unsigned, string> substractForm{
            {4, "IV"},
            {9, "IX"},
            {40, "XL"},
            {90, "XC"},
            {400, "CD"},
            {900, "CM"}
        };

        int decimal = 4;
        string ans;
        while(decimal--){
            int de = pow(10, decimal);
            if(num < de) continue;

            int val = num / de;
            int representing = val * de;

            if(val == 4 || val == 9){
                auto pos = substractForm.find(representing);
                if(pos != substractForm.end()){
                    ans += pos->second;
                }
            }else{
                int tmp = representing;
                while(tmp){
                    for(auto itr = symbols.rbegin(); itr != symbols.rend(); ++itr){
                        if(tmp >= itr->first){
                            int t = tmp / itr->first;
                            ans += string(t, itr->second);
                            tmp %= itr->first;
                            break;
                        }
                    }
                }
            }
            num -= representing;
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};
// @lc code=end
#include <iostream>

int main(){
    Solution s;
    cout << s.intToRoman(3000) << endl;
    cout << s.intToRoman(3749) << endl;
    cout << s.intToRoman(58)   << endl;
    cout << s.intToRoman(1994) << endl;
    return 0;
}
