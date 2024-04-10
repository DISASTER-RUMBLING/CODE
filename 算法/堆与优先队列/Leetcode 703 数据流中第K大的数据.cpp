#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<vector>
using namespace std;

class KthLargest {
    int K;
    multiset<int> st;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            st.insert(n);
            if (st.size() > k) st.erase(st.begin());
        }
        K = k;

    }

    int add(int val) {
        st.insert(val);
        if (st.size() > K) st.erase(st.begin());
        return *st.begin();
    }
};