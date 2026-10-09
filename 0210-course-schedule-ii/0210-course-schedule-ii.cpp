
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph: prerequisite -> course
        for (auto& p : prerequisites) {
            int course = p[0];
            int pre = p[1];

            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            order.push_back(course);

            for (int next : adj[course]) {
                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // A cycle means not all courses can be completed
        if (order.size() != numCourses)
            return {};

        return order;
    }
};