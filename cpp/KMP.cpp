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
 */
class KMP{
public:
    int findPattern(const string& input, const string& pattern){

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
        vector<int> ans(pattern.size(), 0);
        for(int i = 0; i < pattern.size(); ++i){
            for(int k = 0; k < i; ++k){
                if(pattern.substr(0, k) == pattern.substr(i - k + 1, k))
                    ans[i] = k;
            }
        }
        return ans;
    }
};

int main(){
    string test1 = "abcdefgh";
    string pattern1 = "def";


    string test2 = "abcdabcabcdf";
    string pattern2 = "abcdf";


    string prefixTest = "abcabcd";
    KMP solution;
   
    for (auto &&i : solution.calKMPPrefixArray(prefixTest))
    {
        cout<<','<<i;
    }
    
}