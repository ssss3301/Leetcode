#include <vector>
#include <unordered_map>

std::vector<int> TwoSum(std::vector<int>& nums, int target) {
	std::vector<int> ret;
	std::unordered_map<int, int> tmp_map;
	for (int i = 0; i < nums.size(); ++i) {
		std::unordered_map<int, int>::const_iterator iter = tmp_map.find(target - nums[i]);
		if (iter == tmp_map.end()) {
			tmp_map[nums[i]] = i;
		}
		else {
			ret.push_back(i);
			ret.push_back(iter->second);
		}
	}
	return ret;
}