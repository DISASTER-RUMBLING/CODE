#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Solution {
public:
	string breakPalindrome(string palindrome) {
		if (palindrome.size() == 1) {
			return "";
		}
		int sz = palindrome.size(), flag = 0;
		for (int i = 0; i < sz; i++) {
			if (palindrome[i] != 'a' && i != sz / 2) {
				palindrome[i] = 'a';
				flag = 1;
				break;
			}
		}
		if (!flag) {
			palindrome[sz - 1] = 'b';
		}
		return palindrome;
	}
};