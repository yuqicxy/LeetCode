// Median of two sorted array.cpp : Defines the entry point for the application.
//

#include "Median of two sorted array.h"

using namespace std;

int main()
{
	Solution s;
	try
	{
		std::vector<int> nums1 = {1,3};
		std::vector<int> nums2 = {2};
		auto median = s.findMedianSortedArrays(nums1,nums2);
		cout << median << endl;
	}
	catch (...) {
		cout << "some error happen" << endl;
	}
	return 0;
}
