#define _crt_secure_no_warnings
#include<iostream>
#include<map>

using namespace std;

char p;
string now, dad;
//第一个string表示儿子，第二个string表示父亲
map<string, string> arr;

string find(string now,int deep) {
	if (arr.find(now) != arr.end()) {
		return find(arr[now], deep + 1);
	}
	return now;
}

int main() {
	
	cin >> p;
	int times = 0;
	while (p != '$') {
		cin >> now;
		if (p == '#') {
			dad = now;
		}
		else if (p == '+') {
			arr[now] = dad;
		}
		else if (p == '?') {
			cout << now << " " << find(now, 0) << endl;
		}
		cin >> p;
	}

	return 0;
}