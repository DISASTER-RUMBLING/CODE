#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:


    map<int, int> use;
    int sz;

    int dfs(vector<Employee*> employees, int id) {
        if (use[id]) {
            return 0;
        }
        int ans = 0, num;
        for (int i = 0; i < sz; i++) {
            if (employees[i]->id == id) {
                ans = employees[i]->importance;
                num = i;
                break;
            }
        }
        for (int i = 0; i < employees[num]->subordinates.size(); i++) {
            ans += dfs(employees, employees[num]->subordinates[i]);
        }
        return ans;
    }

    int getImportance(vector<Employee*> employees, int id) {
        sz = employees.size();
        dfs(employees, id);
        return dfs(employees, id);
    }


};