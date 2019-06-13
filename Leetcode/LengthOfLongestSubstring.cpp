#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
	string longest_substr;
	string cur_substr;
	int start_pos = 0;
	unordered_map<char, int> tmp;
	for (int i = 0; i < s.size(); ++i) {
		std::unordered_map<char, int>::const_iterator iter = tmp.find(s[i]);
		if (iter != tmp.end()) {
			cur_substr = s.substr(start_pos, i - start_pos);
			if (cur_substr.size() > longest_substr.size()) {
				longest_substr = cur_substr;
			}
			start_pos = iter->second + 1;
			tmp.clear();
		}
		tmp[s[i]] = i;
	}

	cur_substr = s.substr(start_pos, s.size() - start_pos);
	if (cur_substr.size() > longest_substr.size())
		longest_substr = cur_substr;

	return longest_substr.size();
}

int lengthOfLongestSubstring2(string s) {
	int idx_array[256];
	for (int i = 0; i < 256; ++i) {
		idx_array[i] = -1;
	}

	int max_len = 0;
	int start_pos = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (idx_array[s[i]] != -1) {
			max_len = (i - start_pos > max_len ? i - start_pos : max_len);
			if (idx_array[s[i]] + 1 > start_pos) {
				start_pos = idx_array[s[i]] + 1;
			}
			idx_array[s[i]] = -1;
		}
		idx_array[s[i]] = i;
	}

	max_len = (s.size() - start_pos > max_len ? s.size() - start_pos : max_len);

	return max_len;
}