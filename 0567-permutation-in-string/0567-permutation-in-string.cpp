class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> hash1(26,0);
        vector<int> hash2(26,0);

        for(int i = 0;i<s1.size();i++){
            hash1[s1[i] - 'a']++;
        }
        int i = 0;
        int j = s1.size()-1;

        for(int k = 0;k<=j;k++){
            hash2[s2[k] - 'a']++;
        }

        while(j < s2.size()-1){
            // cout<<i<<" "<<j<<endl;
            // for(auto it:hash2){
            //     cout<<it<<" ";
            // }
            cout<<endl;
            if(hash1 == hash2) return true;

            i++;
            j++;
            hash2[s2[j]-'a']++;
            hash2[s2[i-1] - 'a']--;
        }

        return hash1 == hash2;
    }
};