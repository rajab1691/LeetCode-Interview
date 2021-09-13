// https://leetcode.com/problems/permutations/
/*
    The time and space complexity should be O(n * n!) since it filled the vector<vector> res which has n! vectors and each of has n elements.
*/

class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return {};
        
        helper(0,nums);
        return res;
    }
    void helper(int idx,vector<int>&nums){
        
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            helper(idx+1,nums);
          //the num vector is passed by reference, so if it is not not reset, the next iteration will have the wrong vector to begin,ie..backtracking
            swap(nums[idx],nums[i]);
        }
        
    }
};
