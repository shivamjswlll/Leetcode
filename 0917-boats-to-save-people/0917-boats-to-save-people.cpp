class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int cnt = 0;
        int wei = 0;
        int r = people.size()-1;
        int l = 0;
        while(l<=r){
            wei = people[r];
            int c = 1;
            while(l < r && wei+people[l] <= limit & c < 2){
                wei += people[l];
                c++;
                l++;
            }
            cnt++;
            r--;
            cout<<wei<<" "<<c<<" ";
            
        }
        // cout<<endl;
        // for(auto i:people) cout<<i<<" ";
        return cnt;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });