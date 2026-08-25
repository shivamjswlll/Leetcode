class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;

        for(int i = 0;i<points.size();i++){
            int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({distance,{points[i][0],points[i][1]}});
        }
        vector<vector<int>> ans;

        while(k--){
            auto it= pq.top().second;
            pq.pop();
            ans.push_back(it);
        }

        return ans;
    }
};