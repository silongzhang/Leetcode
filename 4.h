// #4 寻找两个有序数组的中位数

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) {
			std::swap(nums1, nums2);
		}
		int iMin = 0, iMax = nums1.size();
		const int half = (nums1.size() + nums2.size() + 1) / 2;
		while (iMin <= iMax) {
			int i = (iMin + iMax) / 2;
			int j = half - i;
			if (i < iMax && nums1[i] < nums2[j - 1]) {
				iMin = i + 1;
			}
			else if (i > iMin && nums1[i - 1] > nums2[j]) {
				iMax = i - 1;
			}
			else {
				int maxLeft;
				if (i == 0) maxLeft = nums2[j - 1];
				else if (j == 0) maxLeft = nums1[i - 1];
				else maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
				if ((nums1.size() + nums2.size()) % 2 == 1) return maxLeft;

				int minRight;
				if (i == nums1.size()) minRight = nums2[j];
				else if (j == nums2.size()) minRight = nums1[i];
				else minRight = std::min(nums1[i], nums2[j]);
				return (maxLeft + minRight) / 2.0;
			}
		}
		return 0.0;
	}
};

