class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if(n<=2) return {};
        vector<vector<int>> ans;
        vector<int> prime(n,1);
        unordered_map<int,int> mp;
        prime[0] = 0;
        prime[1] = 0;
        for(int i = 2;i*i<=n;i++){
            for(int j = i*i;j<n;j+=i){
                prime[j] = 0;
            }
        }
        for(int i = 0;i<n;i++){
            if(prime[i]){
                mp[i]++;
            }
        }
        for(int i = 0;i<=n/2;i++){
            if(prime[i]){
                int fnd = n-i;
                if(mp.find(fnd) != mp.end()){
                    ans.push_back({i,fnd});
                }
            }
            // cout<<prime[i]<<" ";
        }

        return ans;
    }
};