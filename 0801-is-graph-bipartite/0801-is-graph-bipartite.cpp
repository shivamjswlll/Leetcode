class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V);

        for(int i = 0;i<V;i++){
            if(color[i] == 0){
                queue<pair<int,int>> q;
                q.push({i,1});
                

                while(!q.empty()){
                    int node = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    color[node] = col;

                    for(auto it:graph[node]){
                        if(!color[it]){
                            if(col == 1) q.push({it,2});
                            if(col == 2) q.push({it,1});
                        }
                        else if(color[it] == color[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};