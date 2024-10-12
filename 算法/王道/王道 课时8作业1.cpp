#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct node {
	int num;
	string name;
	char sex;
};

int main() {

	node peo;
	cin >> peo.num >> peo.name >> peo.sex;
	cout << peo.num << " " << peo.name << " " << peo.sex << endl;

	return 0;
}