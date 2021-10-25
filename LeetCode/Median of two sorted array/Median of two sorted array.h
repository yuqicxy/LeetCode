// Median of two sorted array.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
// TODO: Reference additional headers your program requires here.
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& A, std::vector<int>& B) {
        const size_t M = A.size();
        const size_t N = B.size();
        if (M > N) return findMedianSortedArrays(B, A);
        double max_of_left = 0, min_of_right = 0;
        size_t imin = 0, imax = M;
        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = (M + N + 1) / 2 - i;

            if (i > 0 && A.at(i - 1) > B.at(j)) {
                imax = i - 1;
            }
            else if (i < M && B.at(j - 1) > A.at(i)) {
                imin = i + 1;
            }
            else {
                if (i == 0) max_of_left = B.at(j - 1);
                else if (j == 0) max_of_left = A.at(i - 1);
                else max_of_left = max(A.at(i - 1), B.at(j - 1));

                if ((M + N) % 2 == 1) {
                    return max_of_left;
                }

                if (i == M) min_of_right = B.at(j);
                else if (j == N) min_of_right = A.at(i);
                else min_of_right = min(A.at(i), B.at(j));

                return (max_of_left + min_of_right) / 2.0f;
            }
        }
        return 0;
    }
};