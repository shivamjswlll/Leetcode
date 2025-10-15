class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> Indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            Indegree[v]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0;i<numCourses;i++){
            if(Indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node]){
                Indegree[it]--;
                if(Indegree[it] == 0) q.push(it);
            }
        }

        if(ans.size() != numCourses) return {};
        return ans;
    }
};