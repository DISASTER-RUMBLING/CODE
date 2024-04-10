#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>

using namespace std;

#define ll long long

ll n;
map<ll, ll> arr;

int main() {

	scanf("%lld", &n);
	while (n--) {
		ll cho, lon;
		scanf("%lld%lld", &cho, &lon);
		if (cho == 1) {
			if (arr[lon] == 1) {
				printf("Already Exist\n");
				continue;
			}
			arr[lon]++;
		}
		else if (cho == 2) {
			if (arr.empty()) {
				printf("Empty\n");
				continue;
			}
			else if (arr.count(lon)) {
				printf("%lld\n", lon);
				arr.erase(lon);
				continue;
			}
			else {
				arr[lon] = 1;
				auto now = arr.find(lon);
				auto next = now;
				next++;
				//没有比长度为lon短的木头时
				if (now == arr.begin()) {
					printf("%lld\n", (next)->first);
					arr.erase(next);
				}
				//没有比长度为lon长的木头时
				else if (next == arr.end()) {
					now--;
					printf("%lld\n", now->first);
					arr.erase(now);
				}
				else {
					//当既有比长度为lon长的和短的木头时
					//长的长度更接近lon时
					if ((next->first - lon) > (lon - (--now)->first)) {
						printf("%lld\n", now->first);
						arr.erase(now);
					}
					//短的长度更接近lon时
					else {
						printf("%lld\n", next->first);
						arr.erase(next);
					}
				}
				arr.erase(lon);
			}
		}
	}

	return 0;
}