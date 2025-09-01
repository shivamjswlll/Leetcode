class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        unordered_map<char,int> mpeven,mpodd;
        for(int i = 0;i< n;i+=2){
            mpeven[s1[i]]++;
            if(i != 0)
                mpodd[s1[i-1]]++;
        }
        if(n % 2 == 0) mpodd[s1[n-1]]++;

        unordered_map<char,int> mppeven,mppodd;
        for(int i = 0;i< n;i+=2){
            mppeven[s2[i]]++;
            if(i != 0)
                mppodd[s2[i-1]]++;
        }
        if(n % 2 == 0) mppodd[s2[n-1]]++;

        return mpeven == mppeven && mpodd == mppodd;
    }
};