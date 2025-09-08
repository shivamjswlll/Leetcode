class Solution {
    bool isValid(int n){
        while(n){
            int a = n % 10;
            if(a==0) return false;
            n = n/10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        int cnt = 1;
        while(cnt){
            int second = n-cnt;
            if(isValid(cnt) && isValid(second)) return {cnt,second};
            else cnt++;
        }
        return {};
    }
};