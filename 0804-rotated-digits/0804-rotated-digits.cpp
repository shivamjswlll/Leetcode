class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            bool flag = true;
            string num = to_string(i);
            string res = "";
            for(int j = 0;j<num.size();j++){
                if(num[j] == '0') res += '0';
                else if(num[j] == '1') res += '1';
                else if(num[j] == '2') res += '5';
                else if(num[j] == '5') res += '2';
                else if(num[j] == '6') res += '9';
                else if(num[j] == '8') res += '8';
                else if(num[j] == '9') res += '6';
                else{
                    flag = false;
                    break;
                }
            }
            if(flag && num != res) cnt++;
        }
        return cnt;
    }
};