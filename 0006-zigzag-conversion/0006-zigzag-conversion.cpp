class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> vec(numRows,"");
        int row = 0;
        bool down = false;

        for(int i = 0;i<s.size();i++){

            if(row == 0){
                down = true;
            }
            if(row == numRows-1){
                down = false;
            }

            vec[row] += s[i];

            if(down) row++;
            else row--;
        }
        string ans = "";
        for(auto &i:vec){
            ans += i;
        }
        return ans;
    }
};