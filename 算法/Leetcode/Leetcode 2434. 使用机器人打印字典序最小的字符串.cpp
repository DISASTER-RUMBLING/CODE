#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

bool Check(int*  chnum, char now) {
	for (int i = 0; i < (int)(now - 'a'); i++) {
		if (chnum[i]) {
			return true;
		}
	}
	return false;
}

string robotWithString(string s) {
	int now = 0, num = -1, sz = s.size();
	string res="";
	char arr[100005];
	int chnum[27] = { 0 };
	for (int i = 0; i < sz; i++) {
		chnum[(int)(s[i] - 'a')] += 1;
	}
	while (res.size() < sz) {
		if((num == -1 && now<sz)) {
			arr[++num] = s[now];
			chnum[(int)(s[now++] - 'a')] -= 1;
		}
		else if (!Check(chnum, arr[num]) || sz==now) {
			res += arr[num--];
		}
		else if(now<sz){
			arr[++num] = s[now];
			chnum[(int)(s[now++] - 'a')] -= 1;
		}
	}
	return res;
}

int main() {
	robotWithString("zza");
}