#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>

using namespace std;

#define ll long long

ll n, op, sc;
string na;
map<string, ll> arr;

int main() {

	scanf("%lld", &n);
	while (n--) {

		scanf("%lld", &op);
		if (op < 4) {
			cin >> na;
		}
		if (op == 1) {
			scanf("%lld", &sc);
			arr[na] = sc;
			printf("OK\n");
		}
		else if (op == 2) {
			if (arr.count(na)) {
				printf("%lld\n", arr[na]);
			}
			else {
				printf("Not found\n");
			}
		}
		else if (op == 3) {
			if (arr.count(na)) {
				arr.erase(na);
				printf("Deleted successfully\n");
			}
			else {
				printf("Not found\n");
			}
		}
		else {
			printf("%lld\n", arr.size());
		}
	}

	return 0;
}