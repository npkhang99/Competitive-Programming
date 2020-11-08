/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, bool> visited;
    unordered_map<int, int> importance;
    unordered_map<int, vector<int>> adj;

    int dfs(int u) {
        visited[u] = true;
        int subordinates_total_importance = 0;
        for (int v : adj[u]) {
            if (!visited[v]) {
                subordinates_total_importance += dfs(v);
            }
        }
        return subordinates_total_importance + importance[u];
    }

    int getImportance(vector<Employee*> employees, int id) {
        // sort(employees.begin(), employees.end());
        for (Employee* employee : employees) {
            importance[employee->id] = employee->importance;
            visited[employee->id] = false;
            for (int subordinate : employee->subordinates) {
                adj[employee->id].push_back(subordinate);
            }
        }

        return dfs(id);
    }
};
