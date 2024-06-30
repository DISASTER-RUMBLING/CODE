#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

int dfs(vector<int>& nums, int target, int now, int sum) {
    if (now > nums.size()) {
        return sum == target ? 1 : 0;
    }
    int ans = 0;
    ans += dfs(nums, target, now + 1, sum + nums[now]);
    ans += dfs(nums, target, now + 1, sum - nums[now]);
    return ans;
}

int findTargetSumWays(vector<int>& nums, int target) {
    return dfs(nums, target, 0, 0);
}

int main() {

    vector<int> a = { 1,1,1,1,1 };
    int res = findTargetSumWays(a, 3);

    return 0;
}