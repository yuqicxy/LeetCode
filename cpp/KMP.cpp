/**
 * @file KMP.cpp
 * @author Qi Yu (qi.yu@g42.ai)
 * @brief 
 * @version 0.1
 * @date 2024-09-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief Knuth Morris Pnatt algorithm (substring matching)
 * 
 *  https://www.youtube.com/watch?v=V5-7GzOfADQ
 * 
 */
class KMP{
public:
    int findPattern(const string& input, const string& pattern){
        vector<int> pi = calKMPPrefixArray(pattern);
        int j = 0;
        for(size_t i = 0; i < input.size(); ++i){
            bool flag  = true;
            while(!(j < 0) && input[i] != pattern[j])
                j = pi[j] - 1;
            j++;
            if(!(j < pi.size())) return (int)(i - pattern.size()) + 1;
        }
        return -1;
    }

    /**
     * @brief KMP Prefix
     * 
     * Compute KMP Prefix based on the function below
     * 
     * https://cp-algorithms.com/string/prefix-function.html
     * 
     * e.g. 
     * For string               "a b c a b c d" 
     * prefix function(PI ) is  [0 0 0 1 2 3 0] 
     * 
     * @param pattern search pattern of KMP algorithms
     * @return std::vector<size_t>  prefix value, vector length is equal to string size of pattern 
     */
    vector<int> calKMPPrefixArray(const string& pattern){
        vector<int> pi(pattern.size(), 0);
        for(int i = 1; i < pattern.size(); ++i){
            int j = pi[i - 1];
            while(j > 0 && pattern[i] != pattern[j])
                j = pi[j - 1];
            if(pattern[i] == pattern[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
};

int main(){
    KMP solution;

    string test1 = "abcdefgh";
    string pattern1 = "def";
    cout << solution.findPattern(test1,pattern1) << endl; /** pos 3 */

    string test2 = "abcdabcabcdf";
    string pattern2 = "abcdf";
    cout << solution.findPattern(test2,pattern2) << endl; /** pos 7 */

    string test3 = "abcdabcabcdf";
    string pattern3 = "dd";
    cout << solution.findPattern(test3,pattern3) << endl; /** pos -1 */

    string prefixTest = "ababcababa";
   
    for (auto &&i : solution.calKMPPrefixArray(prefixTest))
        cout<<','<<i;
}