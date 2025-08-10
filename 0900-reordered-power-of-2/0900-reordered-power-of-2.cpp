class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int,int> mp;
        int multiplier = 1;
        while(multiplier < 1e9){
            mp[multiplier]++;
            multiplier *= 2;
        }
        string s = to_string(n);
        if(mp.find(stoi(s)) != mp.end()) return true;
        string temp = s;
        next_permutation(temp.begin(),temp.end());
        while(temp != s){
            if(temp[0] != '0'){
                if(mp.find(stoi(temp)) != mp.end()) return true;
            }
            next_permutation(temp.begin(),temp.end());
        }

        return false;
    }
};