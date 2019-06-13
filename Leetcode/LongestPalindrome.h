#pragma once
#include <string>
using namespace std;

string longestPalindrome_violence(string s) {
	int maxlen = 0;
	string maxstr;
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		for (int j = i; j < len; ++j) {
			bool is_palindrome = true;
			int sub_len = j - i + 1;
			for (int k = 0; k < sub_len / 2; ++k) {
				if (s[i + k] != s[i + sub_len - k - 1]) {
					is_palindrome = false;
					break;
				}
			}
			if (is_palindrome) {
				if (sub_len > maxlen) {
					maxstr = s.substr(i, j - i + 1);
					maxlen = sub_len;
				}
			}
		}
	}

	return maxstr;
}