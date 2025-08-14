class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = -1;
        string a = "";
        for(int i = 0;i<num.size()-2;i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                string temp = num.substr(i,3);
                int tp = stoi(temp);
                if(tp > ans){
                    a = temp;
                    ans = tp;
                }
            }
        }
        if(ans == -1) return "";

        return a;
    }
};