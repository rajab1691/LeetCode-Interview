// https://leetcode.com/problems/permutations-ii/

/*Same as Permutation Just storing the unique permutation in set every time*/

//Method-1 with extra space
class Solution {
public:
    vector<vector<int>>res;
    set<vector<int>>s;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();        
        if(n==0)return res;
        //sort(nums.begin(),nums.end());
        helper(0,nums);
        return res;
        
    }
    void helper(int idx,vector<int>& nums){
        if(idx==nums.size()){
            if(s.find(nums)==s.end()){
                res.push_back(nums);
                s.insert(nums);
            }
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            helper(idx+1,nums);
            swap(nums[i],nums[idx]);
        }
    }
};

//Method-2 without extra space using Sorting

class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)return res;
        sort(nums.begin(), nums.end());
        helper(0, nums);
        return res;

    }
  //passing nums by pass by value and sort to avoid duplicates and don't do  extra swap
    void helper(int idx, vector<int>nums) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            if (i != idx and nums[i] == nums[idx]) {
                continue;
            }
            swap(nums[i], nums[idx]);
            helper(idx + 1, nums);
        }
    }
};
