class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i = 0;i<points.size();i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int dist = x1*x1 + y1*y1;
            pq.push({dist,{x1,y1}});
        }
        while(k--){
            auto it = pq.top();
            pq.pop();
            int x1 = it.second.first;
            int y1 = it.second.second;
            ans.push_back({x1,y1});
        }

        return ans;
    }
};