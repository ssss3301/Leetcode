#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size()) {
		std::vector<int> tmp = nums1;
		nums1 = nums2;
		nums2 = tmp;
	}

	int iMin = 0;
	int iMax = nums1.size();
	int halfLen = (nums1.size() + nums2.size() + 1) / 2;
	while (iMin <= iMax) {
		int i = (iMin + iMax) / 2;
		int j = halfLen - i;

		if (i > iMin && nums1[i - 1] > nums2[j]) {
			iMax = i - 1;
		}
		else if (i < iMax && nums1[i] < nums2[j - 1]) {
			iMin = i + 1;
		}
		else {
			int maxleft;
			if (i == 0) {
				maxleft = nums2[j - 1];
			}
			else if (j == 0) {
				maxleft = nums1[i - 1];
			}
			else {
				maxleft = std::max(nums1[i - 1], nums2[j - 1]);
			}

			if ((nums1.size() + nums2.size()) % 2 != 0)
				return maxleft;

			int minRight;
			if (i == nums1.size()) {
				minRight = nums2[j];
			}
			else if (j == nums2.size()) {
				minRight = nums1[i];
			}
			else {
				minRight = std::min(nums1[i], nums2[j]);
			}

			return (maxleft + minRight) / 2.0;
		}
	}

	return 0.0;
} 