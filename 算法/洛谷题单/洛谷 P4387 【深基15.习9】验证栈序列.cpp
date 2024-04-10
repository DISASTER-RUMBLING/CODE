#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>

using namespace std;

int n, push[100005], pop[100005];
stack<int> arr;

int main() {

	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);
		for (int i = 1; i <= num; i++) {
			scanf("%d", &push[i]);
		}
		for (int i = 1; i <= num; i++) {
			scanf("%d", &pop[i]);
		}
		int n_pop = 1, n_push = 1;
		while (n_push <= num) {
			arr.push(push[n_push++]);
			while (!arr.empty()&& arr.top() == pop[n_pop]) {
				n_pop++;
				arr.pop();
			}
		}
		if (arr.empty()) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
			while (!arr.empty()) {
				arr.pop();
			}
		}
		
	}

	return 0;
}