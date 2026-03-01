#include<iostream>

using namespace std;

class Solution {
public:
	int minPartitions(string n) {
		char num = '0';
		for (int i = 0; i < n.size(); i++) {
			num = n[i] > num ? n[i] : num;
		}
		return num - '0';
	}
};