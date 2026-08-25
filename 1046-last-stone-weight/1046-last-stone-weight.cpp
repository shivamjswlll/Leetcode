class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i = 0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(!pq.empty() & pq.size() >= 2){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x==y) continue;
            if(x!=y){
                pq.push(y-x);
            }
        }
        if(pq.size() == 0){
            return 0;
        }
        return pq.top();
    }
};