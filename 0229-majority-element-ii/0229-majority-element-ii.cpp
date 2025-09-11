class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int first = -1;
     int second = -1;
     int count1 = 0;
     int count2 = 0;

     for(int i = 0;i<nums.size();i++){
        if(nums[i] == first){
            count1++;
        }
        else if(nums[i] == second){
            count2++;
        }
        else if(count1 == 0){
            first = nums[i];
            count1 = 1;
        }
        else if(count2 == 0){
            second = nums[i];
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
     }   
     count1 = count2 = 0;
     int n = nums.size();
     for(int i = 0;i<nums.size();i++){
        if(nums[i] == first) count1++;
        else if(nums[i] == second) count2++;
     }
     if(count1 > n/3 && count2> n/3) return {first,second};
     else if(count1 > n/3) return {first};
     else if(count2 > n/3) return {second};

     return {};
    }
};