#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	map<int, bool> mmp;
	arr[0] = 1;
	mmp[1] = 1;
	for (int i = 1; i < n; i++) {
		int num = arr[i - 1] - i - 1;
		if (num > 0 && !mmp[num]) {
			arr[i] = num;
		}
		else {
			arr[i] = arr[i-1] + i + 1;
		}
		mmp[arr[i]] = 1;
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " "  ;
	}
	return 0;
}