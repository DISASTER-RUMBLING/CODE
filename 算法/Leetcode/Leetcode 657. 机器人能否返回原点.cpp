#include<iostream>

using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int row = 0, col = 0;
		for (int i = 0; i < moves.size(); i++) {
			if (moves[i] == 'R') {
				row++;
			}
			else if (moves[i] == 'L') {
				row--;
			}
			else if (moves[i] == 'U') {
				col++;
			}
			else {
				col--;
			}
		}
		return row == 0 && col == 0;
	}
};