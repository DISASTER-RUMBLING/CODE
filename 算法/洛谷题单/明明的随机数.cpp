#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
using namespace std;

#define read(a) {char c;while((c=getchar())>47) a=a*10+(c^48);}

int main() {

	int n, m;
	scanf("%d", &n);
	set<int> arr;
	int times = 0;
	for (int i = 0,j; i < n; i++) {
		scanf("%d", &j);
		if (arr.find(j) == arr.end()) {
			arr.insert(j);
			times++;
		}
		else {
			continue;
		}
	}
	printf("%d\n", times);
	for (auto x : arr) {
		cout << x << " ";
	}


	return 0;
}