#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
using namespace std;

typedef pair<int, int> PII;

int main() {
	int num, fir, sec, result = 0;//fir是利润，sec是保质期
	set<PII> s1,s2;
	//s1中第一个是保质期，第二个是利润
	//s2中第一个是利润，第二个是保质期
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &fir, &sec);
		s1.insert(PII(sec, fir));
		
	}
	for (int i = 0; i < num; i++) {
		if (s2.size() < s1.begin()->first) {
			s2.insert(PII(s1.begin()->second, s1.begin()->first));
			s1.erase(s1.begin());
		}
		else if (s2.begin()->first < s1.begin()->second) {
			s2.erase(s2.begin());
			s2.insert(PII(s1.begin()->second, s1.begin()->first));
			s1.erase(s1.begin());
		}
	}
	for (auto x:s2) {
		result += s2.begin()->first;
		s2.erase(s2.begin());
	}
	printf("%d", result);

	return 0;
}