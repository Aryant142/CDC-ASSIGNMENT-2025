class Solution {
public:
    bool solve(int numCourses, unordered_map<int, vector<int>>& adj) {
        vector<int> indegree(numCourses, 0);

        // Compute indegree
        for(auto &p : adj) {
            for(int v : p.second) {
                indegree[v]++;
            }
        }

        queue<int> q;

        // Push nodes with indegree 0
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(int neighbor : adj[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return count == numCourses;  // if false → cycle exists
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for(auto &i : prerequisites) {
            int course = i[0];
            int prereq = i[1];
            adj[prereq].push_back(course);  // FIXED direction
        }

        return solve(numCourses, adj);
    }
};
