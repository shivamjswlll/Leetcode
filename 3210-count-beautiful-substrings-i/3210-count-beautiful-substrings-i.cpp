class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            int vowel = 0;
            int conso = 0;
            for(int j = i;j<n;j++){
                if(s[j] == 'a' || s[j] == 'e'|| s[j] == 'i'|| s[j] == 'o'|| s[j] == 'u'){
                    vowel++;
                }
                else{
                    conso++;
                }
                // cout<<vowel<<" "<<conso<<endl;
                if(vowel == conso && (vowel*conso) % k == 0) ans++;
            }
        }
        return ans;

    }
};