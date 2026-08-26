class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        
        string ans = "";

        for(int i = 0;i<s.size();i++){
            //even size
            int l = i;
            int h = i+1;

            while(l>=0 && h < s.size() && s[l] == s[h]){
                int size = h-l+1;
                if(size > ans.size()){
                    ans = s.substr(l,size);
                }
                l--,h++;
            }

            //odd size
            l = i-1;
            h = i+1;

            while(l>=0 && h<s.size() && s[l] == s[h]){
                int size = h-l+1;
                if(size > ans.size()){
                    ans = s.substr(l,size);
                }
                l--,h++; 
            }
        }

        if(ans==""){    
            return s.substr(0,1);
        }
        return ans;

    }
};