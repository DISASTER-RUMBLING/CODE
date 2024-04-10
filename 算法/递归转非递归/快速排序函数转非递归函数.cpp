#define _CRT_SECURE_NO_WARNINGS
#include<stack>
using namespace std;

void Swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
	return;
}

//µÝ¹é°æ±¾
int* Quick_Sort(int* arr, int left, int right) {
	if ((right - left) <= 2) {
		if (arr[left] > arr[right]) {
			Swap(arr + left, arr + right);
		}
		return arr;
	}
	int now = left, l = left + 1, r = right - 1;
	while (l != r) {
		while (arr[now] < arr[r] && l < r) {
			r--;
		}
		if (arr[now] > arr[r]) {
			Swap(arr + now, arr + r);
		}
		now = r;
		while (arr[now] > arr[l] && l < r) {
			l++;
		}
		if (arr[now] > arr[l]) {
			Swap(arr + now, arr + l);
		}
		now = l;
	}
	Quick_Sort(arr, left, l);
	Quick_Sort(arr, l + 1, right);
	return arr;
}

//·ÇµÝ¹é°æ±¾
struct dat {
	int left, right;
	int now, l, r;
	int code;
};

dat* Data(int left, int right) {
	dat* p = (dat*)malloc(sizeof(dat));
	p->left = left;
	p->right = right;
	p->now = left;
	p->l = left + 1;
	p->r = right - 1;
	p->code = 0;
}

int* __Quick_Sort(int* arr, int left, int right) {
	stack<dat*> s;
	dat* p = Data(left, right);
	s.push(p);
	while (!s.empty()) {
		dat* q = s.top();
		switch (q->code) {
			case 0: {
				if ((q->right) - (q->left) <= 2) {
					Swap(arr + (q->left), arr + (q->right));
					s.pop();
				}
				q->code = 1;
			}break;
			case 1: {
				while (q->l != q->r) {
					while (arr[q->r] > arr[q->now] && q->l < q->r) {
						q->r--;
					}
					if (arr[q->now] > arr[q->r]) {
						Swap(arr + (q->now), arr + (q->r));
					}
					q->now = q->right;
					while (arr[q->l] < arr[q->now] && q->l < q->r) {
						q->l++;
					}
					if (arr[q->l] > arr[q->now]) {
						Swap(arr + (q->l), arr + (q->now));
					}
					q->now = q->l;
				}
				q->code = 2;
			}break;
			case 2: {
				dat* j = Data(q->left, q->l);
				q->code = 3;
				s.push(j);
			}break;
			case 3: {
				dat* k = Data(q->l + 1, q->right);
				q->code = 4;
				s.push(k);
			}break;
			case 4: {
				s.pop();
			}
		}
	}
	return arr;
}