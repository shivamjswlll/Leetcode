class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(s.size() != target.size()) return false;

        int zero = 0;
        int one = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0') zero++;
            else{
                one++;
            }
        }

        
        for(int i = 0;i<s.size();i++){
            if(s[i] != target[i]){
                if(s[i] == '0'){
                    if(one < 1) return false;
                    else{
                        one++;
                    }
                }
            }
        }
        for(int i = 0;i<s.size();i++){
            if(s[i] != target[i]){
                if(s[i] == '1'){
                    if(one < 2) return false;
                    else one--;
                }
            }
        }
        return true;
    }
};