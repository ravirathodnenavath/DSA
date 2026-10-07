class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // adj[a] = courses that can be taken after completing a
        vector<vector<int>> adj(numCourses);

        // indegree[i] = number of prerequisites required for course i
        vector<int> indegree(numCourses, 0);

        for (auto prerequisite : prerequisites) {

            int course = prerequisite[0];
            int pre = prerequisite[1];

            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Courses with no prerequisites can be taken first
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {

            int course = q.front();
            q.pop();

            count++;

            // Remove this course as a prerequisite
            for (int next : adj[course]) {

                indegree[next]--;

                // All prerequisites are completed
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If all courses were processed, there is no cycle
        return count == numCourses;
    }
};