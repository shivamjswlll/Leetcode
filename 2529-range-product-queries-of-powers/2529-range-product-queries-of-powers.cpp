class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int sum = 0;
        int cnt = 0;
        vector<int> power;

        int temp = n;
        while(sum != n && cnt <= 32){
            if(temp & (1 << cnt)){
                int num = pow(2,cnt);
                power.push_back(num);
                sum += num;
            }
            cnt++;
        }
        vector<int> ans;
        for(int i = 0;i<queries.size();i++){
            int s = queries[i][0];
            int e = queries[i][1];
            long long total = 1;
            for(int j = s;j<=e;j++){
                total = (total* power[j]) % MOD;
            }
            ans.push_back(total);
        }

        return ans;
    }
};