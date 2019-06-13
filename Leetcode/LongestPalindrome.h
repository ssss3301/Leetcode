#pragma once
#include <string>
#include <algorithm>
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

int palindrome_expand(string& s, int left, int right) {
	int len = s.size();
	while (left >= 0 && right < len && s[left] == s[right]) {
		left--;
		right++;
	}
	return right - left - 1;
}

string longestPalindrome_middleExpand(string s) {
	int str_len = s.size();
	int max_len = 0;
	int max_start = 0;
	int max_end = 0;
	for (int i = 0; i < str_len; ++i) {
		int palindrome_len1 = palindrome_expand(s, i, i);
		int palindrome_len2 = palindrome_expand(s, i, i + 1);
		int len = std::max(palindrome_len1, palindrome_len2);
		if (len > max_len) {
			max_len = len;
			if (len % 2 == 0)
				max_start = i - len / 2 + 1;
			else
				max_start = i - len / 2;
			max_end = i + len / 2;
		}
	}

	return s.substr(max_start, max_end - max_start + 1);
}