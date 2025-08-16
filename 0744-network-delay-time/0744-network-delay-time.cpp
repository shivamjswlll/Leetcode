class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int> vis(n+1,0);
        int ans = INT_MIN;
        bool flag = true;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int node = it.second;
            if(!vis[node])
            ans = max(ans,time);
            vis[node] = 1;

            for(auto ite:adj[node]){
                int nextNode = ite.first;
                int wt = ite.second;
                if(!vis[nextNode]){
                    pq.push({time+wt,nextNode});
                }
            }
            
        }
         for(int i = 1;i<n+1;i++){
                // cout<<vis[i]<<" ";
                if(vis[i] == 0){
                    flag =false;
                }
            }
         if(flag) return ans;

            return -1;
    }
};